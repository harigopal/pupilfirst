class Question < ApplicationRecord
  belongs_to :community
  belongs_to :creator, class_name: 'User'
  belongs_to :editor, class_name: 'User', optional: true
  belongs_to :archiver, class_name: 'User', optional: true
  has_many :target, dependent: :restrict_with_error
  has_many :answers, dependent: :restrict_with_error
  has_many :comments, as: :commentable, dependent: :restrict_with_error
  has_one :school, through: :community

  has_many :target_questions, dependent: :destroy
  has_many :targets, through: :target_questions
  has_many :text_versions, as: :versionable, dependent: :restrict_with_error

  scope :live, -> { where(archived: false) }
end
