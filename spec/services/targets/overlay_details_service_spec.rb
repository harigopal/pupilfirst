require 'rails_helper'

describe Targets::OverlayDetailsService do
  subject { described_class.new(target, founder_1) }

  let(:target) { create :target, :for_founders }
  let(:startup) { create :startup }
  let(:founder_1) { startup.founders.first }
  let(:founder_2) { startup.founders.second }
  let(:founder_3) { create :founder, startup: startup }
  let!(:timeline_event) { create :timeline_event_with_links, target: target, founders: [founder_1], passed_at: 1.day.ago, latest: true }
  let(:faculty) { create :faculty }
  let(:faculty_feedback) { create :startup_feedback, timeline_event: timeline_event, faculty: faculty, startup: startup }
  let(:quiz) { create :quiz, target: target }
  let(:quiz_question) { create :quiz_question, quiz: quiz }
  let(:answer_1) { create :answer_option, quiz_question: quiz_question }
  let(:answer_2) { create :answer_option, quiz_question: quiz_question }

  before do
    quiz_question.update!(correct_answer: answer_2)
  end

  describe '#all_details' do
    it 'returns the founder statuses, latest event, latest feedback and quiz' do
      pending_founder_ids = [founder_2.id, founder_3.id]

      event = {
        description: timeline_event.description,
        createdAt: timeline_event.reload.created_at,
        title: timeline_event.title,
        attachments: [{ type: 'link', title: 'Private URL', url: 'https://sv.co/private' }, { type: 'link', title: 'Public URL', url: 'https://google.com' }]
      }

      feedback = {
        facultyName: faculty.name,
        feedback: faculty_feedback.feedback,
        facultySlackUsername: faculty.slack_username,
        facultyImageUrl: faculty.user.image_or_avatar_url
      }

      quiz_questions = [{
        index: 0,
        question: quiz_question.question,
        description: quiz_question.description,
        correctAnswerId: answer_2.id,
        answerOptions: array_including(
          [
            { id: answer_2.id, value: answer_2.value, hint: answer_2.hint },
            { id: answer_1.id, value: answer_1.value, hint: answer_1.hint }
          ]
        )
      }]

      all_details = subject.all_details

      expect(all_details).to include(:pendingFounderIds, :latestEvent, :latestFeedback, :quizQuestions)
      expect(all_details[:pendingFounderIds]).to match_array(pending_founder_ids)
      expect(all_details[:latestEvent]).to eq(event)
      expect(all_details[:latestFeedback]).to eq(feedback)
      expect(all_details[:quizQuestions]).to match_array(quiz_questions)
    end
  end
end
