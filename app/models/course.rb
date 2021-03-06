class Course < ApplicationRecord
  validates :name, presence: true
  validates :max_grade, presence: true, numericality: { greater_than: 0 }
  validates :pass_grade, presence: true, numericality: { greater_than: 0, less_than_or_equal_to: :max_grade }
  validates :grade_labels, presence: true
  validate :grade_labels_must_match_grades

  belongs_to :school
  has_many :levels, dependent: :restrict_with_error
  has_many :startups, through: :levels
  has_many :founders, through: :startups
  has_many :users, through: :founders
  has_many :target_groups, through: :levels
  has_many :targets, through: :target_groups
  has_many :timeline_events, through: :targets
  has_many :evaluation_criteria, dependent: :restrict_with_error
  has_many :faculty_course_enrollments, dependent: :destroy
  has_many :faculty, through: :faculty_course_enrollments
  has_many :community_course_connections, dependent: :restrict_with_error
  has_many :communities, through: :community_course_connections
  has_many :course_exports, dependent: :destroy

  normalize_attribute :about

  def short_name
    name[0..2].upcase.strip
  end

  def facebook_share_disabled?
    name.include? 'Apple'
  end

  # Hack to enable editing grade_labels as an activeadmin text field
  def grade_labels=(labels)
    labels.is_a?(String) ? super(JSON.parse(labels)) : super(labels)
  end

  def ended?
    ends_at.present? && ends_at.past?
  end

  def grade_labels_to_props
    grade_labels.map do |key, value|
      { grade: key.to_i, label: value }
    end
  end

  private

  def grade_labels_must_match_grades
    return if grade_labels.is_a?(Hash) && grade_labels.keys.map(&:to_i) == [*1..max_grade]

    errors[:grade_labels] << 'do not match available grades'
  end
end
