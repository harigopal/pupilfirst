module Targets
  class AutoVerificationService
    def initialize(target, founder)
      @target = target
      @founder = founder
    end

    def auto_verify
      @target.timeline_events.create!(
        founders: founders,
        description: description,
        passed_at: Time.zone.now,
        latest: true
      )
    end

    private

    def description
      "Target '#{@target.title}' was automatically marked complete."
    end

    def founders
      if @target.founder_event?
        [@founder]
      else
        @founder.startup.founders
      end
    end
  end
end
