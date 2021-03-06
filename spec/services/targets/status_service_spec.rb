require 'rails_helper'

describe Targets::StatusService do
  subject { described_class.new(founder_target_1, founder_1) }

  let(:course) { create :course }
  let(:level_1) { create :level, :one, course: course }
  let(:level_2) { create :level, :two, course: course }
  let(:startup) { create :startup, level: level_2 }
  let(:founder_1) { startup.founders.first }
  let!(:founder_2) { create :founder, startup: startup }
  let(:target_group) { create :target_group, level: level_2 }
  let(:founder_target_1) { create :target, target_group: target_group, role: Target::ROLE_FOUNDER }

  describe '#status' do
    context 'when the target has no submissions' do
      context 'when the course is locked' do
        let(:course) { create :course, ends_at: 1.day.ago }

        it "returns :course_locked" do
          expect(subject.status).to eq(Targets::StatusService::STATUS_COURSE_LOCKED)
        end
      end

      context "when the student's access has ended" do
        let(:startup) { create :startup, level: level_2, access_ends_at: 1.day.ago }

        it "returns :access_locked" do
          expect(subject.status).to eq(Targets::StatusService::STATUS_ACCESS_LOCKED)
        end
      end

      context 'when the target is not locked for any reason' do
        it 'returns :pending' do
          expect(subject.status).to eq(Targets::StatusService::STATUS_PENDING)
        end
      end

      context 'when the target is from a higher level than the startup' do
        let(:startup) { create :startup, level: level_1 }

        it 'returns :level_locked' do
          expect(subject.status).to eq(Targets::StatusService::STATUS_LEVEL_LOCKED)
        end
      end

      context 'when the target has other prerequisite targets' do
        let(:team_target_1) { create :target, target_group: target_group, role: Target::ROLE_TEAM }
        let(:founder_target_2) { create :target, target_group: target_group, role: Target::ROLE_FOUNDER }

        before do
          founder_target_1.prerequisite_targets << [team_target_1, founder_target_2]
        end

        context 'when any prerequisites is incomplete' do
          it 'returns :prerequisite_locked' do
            expect(subject.status).to eq(Targets::StatusService::STATUS_PREREQUISITE_LOCKED)
          end
        end

        context 'when all prerequisites are complete' do
          let!(:submission_1) do
            create :timeline_event, founders: [founder_1, founder_2], target: team_target_1, passed_at: 1.day.ago, latest: true
          end

          let!(:submission_2) do
            create :timeline_event, founders: [founder_1], target: founder_target_2, passed_at: 1.day.ago, latest: true
          end

          it 'returns :pending' do
            expect(subject.status).to eq(Targets::StatusService::STATUS_PENDING)
          end
        end
      end

      context 'when the target is a milestone target' do
        let(:level_2_milestone_target_group) do
          create :target_group, level: level_2, milestone: true
        end
        let(:founder_target_1) do
          create :target, target_group: level_2_milestone_target_group, role: Target::ROLE_FOUNDER
        end
        let(:level_1_milestone_target_group) do
          create :target_group, level: level_1, milestone: true
        end
        let!(:level_1_team_target) do
          create :target, target_group: level_1_milestone_target_group, role: Target::ROLE_TEAM
        end
        let!(:leve1_1_founder_target) do
          create :target, target_group: level_1_milestone_target_group, role: Target::ROLE_FOUNDER
        end

        context 'when there are pending milestones in the previous level' do
          it 'returns :milestone_locked' do
            expect(subject.status).to eq(Targets::StatusService::STATUS_MILESTONE_LOCKED)
          end
        end

        context 'when all previous level milestones are completed' do
          let!(:submission_1) do
            create :timeline_event, founders: [founder_2, founder_1], target: level_1_team_target, passed_at: 1.day.ago, latest: true
          end

          let!(:submission_2) do
            create :timeline_event, founders: [founder_1], target: leve1_1_founder_target, passed_at: 1.day.ago, latest: true
          end

          it 'returns :pending' do
            expect(subject.status).to eq(Targets::StatusService::STATUS_PENDING)
          end
        end
      end
    end

    context 'when the target has a submission' do
      let!(:submission) { create :timeline_event, founders: [founder_1], target: founder_target_1, latest: true }

      context 'when the submission is not evaluated yet' do
        it 'returns :submitted' do
          expect(subject.status).to eq(Targets::StatusService::STATUS_SUBMITTED)
        end
      end

      context 'when the submission has passed_at set' do
        let!(:submission) { create :timeline_event, founders: [founder_1], target: founder_target_1, passed_at: 1.day.ago, latest: true }

        it 'returns :passed' do
          expect(subject.status).to eq(Targets::StatusService::STATUS_PASSED)
        end
      end

      context 'when the submission was evaluated but passed_at not set' do
        let(:faculty) { create :faculty }
        let!(:submission) do
          create :timeline_event, founders: [founder_1], target: founder_target_1, evaluator: faculty, latest: true
        end

        it 'returns :failed' do
          expect(subject.status).to eq(Targets::StatusService::STATUS_FAILED)
        end
      end
    end
  end
end
