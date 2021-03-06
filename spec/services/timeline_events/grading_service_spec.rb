require 'rails_helper'

describe TimelineEvents::GradingService do
  subject { described_class.new(timeline_event) }

  let(:target) { create :target }
  let(:startup) { create :startup }
  let(:founder) { create :founder, startup: startup }
  let(:faculty) { create :faculty }
  let(:course) { create :course }
  let(:timeline_event) { create :timeline_event, target: target, founders: [founder], latest: true }
  let(:target_with_evaluation_criteria) { create :target }
  let!(:evaluation_criterion_1) { create :evaluation_criterion, course: course }
  let!(:evaluation_criterion_2) { create :evaluation_criterion, course: course }

  before do
    target.evaluation_criteria << [evaluation_criterion_1, evaluation_criterion_2]
  end

  describe '#grade' do
    context 'when provided with an all pass grade' do
      let(:grades) { { evaluation_criterion_1.id => 2, evaluation_criterion_2.id => 3 } }

      it 'awards grades to timeline event for each of the evaluation criteria' do
        subject.grade(faculty, grades)

        expect(timeline_event.reload.timeline_event_grades.count).to eq(2)
        expect(timeline_event.timeline_event_grades.pluck(:evaluation_criterion_id)).to match_array([evaluation_criterion_1.id, evaluation_criterion_2.id])
        expect(timeline_event.passed_at).not_to eq(nil)
        expect(timeline_event.evaluator_id).to eq(faculty.id)
        expect(timeline_event.evaluated_at).not_to eq(nil)
      end

      context 'when trying to grade again' do
        it 'raises exception' do
          subject.grade(faculty, grades)

          expect do
            TimelineEvents::GradingService.new(timeline_event.reload).grade(faculty, grades)
          end.to raise_error(TimelineEvents::GradingService::AlreadyReviewedException)
        end
      end
    end

    context 'when provided with a failed grade' do
      let(:grades) { { evaluation_criterion_1.id => 1, evaluation_criterion_2.id => 3 } }

      it 'awards grades to timeline event for each of the evaluation criteria' do
        subject.grade(faculty, grades)

        expect(timeline_event.reload.timeline_event_grades.count).to eq(2)
        expect(timeline_event.timeline_event_grades.pluck(:evaluation_criterion_id)).to match_array([evaluation_criterion_1.id, evaluation_criterion_2.id])
        expect(timeline_event.passed_at).to eq(nil)
        expect(timeline_event.evaluator_id).to eq(faculty.id)
        expect(timeline_event.evaluated_at).not_to eq(nil)
      end
    end

    context 'when grades are not available for all criteria' do
      let(:grades) { { evaluation_criterion_1.id => 2 } }

      it 'it raises an invalid grade exception' do
        expect { subject.grade(faculty, grades) }.to raise_error("Grading values supplied are invalid: #{grades.to_json}")
      end
    end

    context 'when awarded grade is not within the allowed grades in a course' do
      let(:grades) { { evaluation_criterion_1.id => 2, evaluation_criterion_1.id => 5 } }

      it 'it raises an invalid grade exception' do
        expect { subject.grade(faculty, grades) }.to raise_error("Grading values supplied are invalid: #{grades.to_json}")
      end
    end
  end
end
