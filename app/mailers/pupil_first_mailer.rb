class PupilFirstMailer < ActionMailer::Base
  include Roadie::Rails::Mailer

  default from: "PupilFirst <noreply@pupilfirst.com>"

  layout 'mail/pupil_first'

  protected

  def default_url_options
    { host: Rails.env.production? ? 'www.pupilfirst.com' : 'www.pupilfirst.localhost' }
  end

  def roadie_options
    host_options = default_url_options.merge(protocol: Rails.env.production? ? 'https' : 'http')

    super.merge(url_options: host_options)
  end
end
