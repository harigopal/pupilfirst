module AuthorizeStudent
  include ActiveSupport::Concern

  def authorized?
    # Has access to school
    return false unless current_school.present? && founder.present? && (course.school == current_school)

    # Founder has access to the course
    return false unless !course.ends_at&.past? && !startup.access_ends_at&.past?

    # Founder can complete the target
    target.level.number <= startup.level.number
  end

  def founder
    @founder ||= current_user.founders.joins(:level).where(levels: { course_id: course }).first
  end

  def startup
    @startup ||= founder.startup
  end

  def course
    @course ||= target.course
  end

  def target
    @target ||= Target.find(target_id)
  end

  def founders
    if target.founder_event?
      [founder]
    else
      founder.startup.founders
    end
  end

  def ensure_submittability
    return if target_status == Targets::StatusService::STATUS_PENDING

    errors[:base] << "Target status #{target_status.to_s.humanize}, You cannot submit the target"
  end

  def target_status
    @target_status ||= Targets::StatusService.new(target, founder).status
  end
end
