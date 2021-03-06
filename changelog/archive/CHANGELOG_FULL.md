## Ongoing

- The final module for the MOOC, along with a completion certificate is being prepared. [[Trello]](https://trello.com/c/8kgMZU6H)
- Design for founder dashboard target's expanded view is in progress. [[Trello]](https://trello.com/c/l92nYs9k)
- The `email_inquire` library is being introduced to improve email parsing on the admissions founder registration form. [[Trello]](https://trello.com/c/PzHR2QQj)

## 2017.05.29

- Multiple changes to content were made, related to the admissions process. Trello. [[1]](https://trello.com/c/Vsbplwaa)[[2]](https://trello.com/c/Radw7HxV)
- Google Tag Manager has been integrated with the codebase, replacing separate Google Analytics and Facebook Pixel integrations. Content-security policy rules have been greatly relaxed to allow this. [[Trello]](https://trello.com/c/GhzoYkCl)
- Grade for a completed target is now displayed on the target header component, replacing the contents of the status badge. [[Trello]](https://trello.com/c/8DNdYGaz)
- An option to retake the tour of the dashboard was added to the action-bar dropdown on the page. [[Trello]](https://trello.com/c/Wqdw2Yen)
- Startup's level is now displayed everywhere its stage used to be. [[Trello]](https://trello.com/c/WSBfBhdY)
- More user state information is now sent to Intercom. [[Trello]](https://trello.com/c/hj5qcA1b)
- The `DashboardDataService` has been spec-d. [[Trello]](https://trello.com/c/7Y5lBcE9)
- Fixed a `404` for an image on the `/talent` page. [[Trello]](https://trello.com/c/WslHyBbn)
- Fixed a bug which caused target description to be displayed twice for each target on the founder dashboard. [[Trello]](https://trello.com/c/EI2Y9WIa)
- The redirect URL for founders levelling up to Level 1 was customized for analytics purpose. [[Trello]](https://trello.com/c/h2aMl5NR)
- The _lodash_ library was added to the codebase. [[Trello]](https://trello.com/c/kGt6ky9x)

## 2017.05.22

- Prerequisite target titles are now displayed on the founder dashboard for targets that are blocked by incomplete prerequisites. [[Trello]](https://trello.com/c/DUyG7scO)
- Upcoming (locked) levels are displayed in the level selection dropdown on the founder dashboard. [[Trello]](https://trello.com/c/5njNuXqr)
- An option to archive targets has been added. Archived targets are not displayed on the founder dashboard. [[Trello]](https://trello.com/c/7MnksReM)
- Fixed a bug in email sent after founder registration that could cause the login token to be missing in email. [[Trello]](https://trello.com/c/MNuOfytB)
- Data for level 0 founders displayed in admin interface has been improved. [[Trello]](https://trello.com/c/5LBgTYkP)
- The admissions dashboard has received a minor update. [[Trello]](https://trello.com/c/TSPvNI8a)
- The Review timeline events admin interface has been updated to remove the _Send to Slack_ feature for level 0 events. [[Trello]](https://trello.com/c/ejDHvdIj)
- After admissions screening, the hacker / hustler selection is saved. This data is also sent to Intercom. Trello. [[1]](https://trello.com/c/bl2JLkjW)[[2]](https://trello.com/c/ZuLlgDhZ)
- A few google analytics events (admissions) are now triggered from the client-side. [[Trello]](https://trello.com/c/s1bp0Rj2)
- The action retrieving founder target status for individual targets was moved from `Founders::DashboardController` to `TargetsController`. [[Trello]](https://trello.com/c/SxBQmNtF)
- Fixed an issue with impersonation that caused admin users (impersonating any user) to not see the targets under _Link Target_ dropdown in a timeline event view page. [[Trello]](https://trello.com/c/1j0PupBF)

## 2017.05.15

- Continuous admission process to SV.CO is live! [[Trello]](https://trello.com/c/CDcL2dG3)
- Load time of Founder dashboard has been drastically reduced by introducing `Targets::BulkStatusService` [[Trello]](https://trello.com/c/1eW5xiJp)
- An admin interface page for tracking engineering metrics has been deployed. [[Trello]](https://trello.com/c/IvCcRtXu)
- Feature specs for timeline builder has been restored. [[Trello]](https://trello.com/c/EWg6ulrR)
- Weekly karma points are created at 6:00 PM every week on Monday, and a processing message is displayed on front-end and via vocalist if generation is incomplete. Trello. [[1]](https://trello.com/c/1WE46vnm)[[2]](https://trello.com/c/R1dzEWtF)
- Feature specs for founder dashboard have been rebuilt. [[Trello]](https://trello.com/c/xexlZwZ8)
- The `batched` scope has been excised from the codebase. [[Trello]](https://trello.com/c/VBdDRl5g)
- A bunch of bugs were quashed and a number of improvements were made to the admissions flow. [[Trello]](https://trello.com/c/XyFxaBVk)
- Basic stats were added to admin interface's admissions dashboard. [[Trello]](https://trello.com/c/4KlhMD33)
- The impersonate action link was added to admin interface show pages for _founder_ and _MOOC student_. [[Trello]](https://trello.com/c/NivSQmNk)
- The styling of attachment download option on timeline event feedback was improved. [[Trello]](https://trello.com/c/VUtxnuen)
- Added a delete restriction to `College` if it is in use by a `Founder`. [[Trello]](https://trello.com/c/aSVrTGyS)

## 2017.05.08

- Leaderboard has been updated to display different lists for different levels. Leaderboards are also cached in the database. [[Trello]](https://trello.com/c/txJeGp9d)
- All unused image assets were removed from the repository. [[Trello]](https://trello.com/c/b5gw4MAt)
- Styling for v2 Resource pages were correctly merged into the v2 folder. [[Trello]](https://trello.com/c/vvKerDaL)
- Content on the `/apply` page was updated. Trello. [[1]](https://trello.com/c/8gynvjOj)[[2]](https://trello.com/c/I82P7jpU)
- All use of Vocalist commands is now logged using Ahoy Events. [[Trello]](https://trello.com/c/1Q1d09bp)
- Fixed a crash when prospective applicant form error is handled server-side. [[Trello]](https://trello.com/c/gvIegqoy)
- Founder college identification files were moved to the private S3 bucket. [[Trello]](https://trello.com/c/DB1i8bPp)
- The company name and bank account details were updated on the admissions preselection page. [[Trello]](https://trello.com/c/dkYGmr8G)
- The _Batch Invite_ page was removed from the administration interface. [[Trello]](https://trello.com/c/947mH2JH)
- Target titles on the founder dashboard were updated to be more descriptive. [[Trello]](https://trello.com/c/lZCxO2XF)
- A rake task / service was created to log weekly engineering statistics. [[Trello]](https://trello.com/c/xN92yNL0)

## 2017.05.01

- Access to faculty connect is now restricted using levels. [[Trello]](https://trello.com/c/CfDKI1cF)
- Access to resources (library) is now restricted using levels. [[Trello]](https://trello.com/c/kQoAQU8H)
- Timeline events can now be linked to chores and sessions from the admin interface. [[Trello]](https://trello.com/c/N4RTjVrp)
- Fixed a bug that resulted in incorrect date being displayed as target submission date on the founder dashboard. [[Trello](https://trello.com/c/0c6ck3f7)
- Specs for `InstamojoController`, prospective applicant registration, and founder registration were restored. Trello. [[1]](https://trello.com/c/2ydQ5s84)[[2]](https://trello.com/c/Uti8YQH8)[[3]](https://trello.com/c/2Joid3ts)
- New target fields were added to admin interface. [[Trello]](https://trello.com/c/Lt45mtM4)
- Stale `share_status` field was removed from the `resources` table. [[Trello]](https://trello.com/c/exTXFnP8)
- Fixed intercom actions for new admissions process. [[Trello]](https://trello.com/c/0BmLDVry)
- Subscription stage 2 was merged into `master` - the new admissions process is still hidden under a feature flag. [[Trello]](https://trello.com/c/vC8Vnv3F)
- The `with_email` scope was replaced with a method to return the first entry found. [[Trello]](https://trello.com/c/jCbftY0f)
- The file drawer on the timeline builder now automatically closes when the discard button is clicked. [[Trello]](https://trello.com/c/O6wtgBkv)
- Fixed a buggy switch to private S3 bucket storage for founder's identification proof files. Trello. [[1]](https://trello.com/c/0nwbDLin)[[2]](https://trello.com/c/pJ5HUX1l)

## 2017.04.24

- Founder completion bubbles have been restored to target description on the founder dashboard. [[Trello]](https://trello.com/c/7rz5KVTW)
- Only chored up to level (and excluding zero, when applicable) are loaded. Sessions gets a similar filter on `DashboardDataService`. [[Trello]](https://trello.com/c/QnUwh0rN)
- Gravatars have been replaced with initial icons as placeholder avatars for all users. [[Trello]](https://trello.com/c/K9HSGaAV)
- Faculty connect is restricted to Level 1+ startups. [[Trello]](https://trello.com/c/K7ANtikP)
- The timeline event review interface has been updated to ignore batch when loading pending timeline events. [[Trello]](https://trello.com/c/8628Cl2N)
- Code related to the Coveralls service has been removed. [[Trello]](https://trello.com/c/GBWSDXwM)

## 2017.04.17

- AA: Add a Level filter to Startup#index. [[Trello]](https://trello.com/c/7CKPqiVx)
- Content on the a few web pages were updated. [[Trello]](https://trello.com/c/mNaBcuEC)

## 2017.04.10

- Fixed a bug that prevented founders from viewing target rubrics. [[Trello]](https://trello.com/c/LlYoVzzt)
- Fixed ordering of sessions on the founder dashboard so they are always shown closest to furthest in both upcoming and past session lists. [[Trello]](https://trello.com/c/gziXKIv5)

## 2017.04.03

- Karma point notifications have been implemented. [[Trello]](https://trello.com/c/BdPlBTGX)
- Fixed issues with old SSL certificate (expired). [[Trello]](https://trello.com/c/DzhbmnEI)
- Added form-level validation for founder age on profile edit form. [[Trello]](https://trello.com/c/R0T2ATMI)
- The `/activity` page was removed because it had low activity, and wasn't linked from anywhere in the v2 design pages. [[Trello]](https://trello.com/c/EI2kpdPQ)
- Added a check to validate length of timeline event description before submitting on the timeline builder. [[Trello]](https://trello.com/c/n3ypLoxM)
- Founder `resume_url` is now computed by default instead of saving the timeline event file / link URL when resume event is verified. [[Trello]](https://trello.com/c/tvyDeNfR)
- Added location information to emails exported from Intercom to SendInBlue. [[Trello]](https://trello.com/c/5zW43FSk)
- Improved Intercom `InactiveUserDeletionService` to remove all stale users instead of just _conversing users_. [[Trello]](https://trello.com/c/qtK7vbZ4)
- Poltergeist / PhantomJS was replaced with Selenium / Chrome to increase reliability of JS-dependant feature specs. [[Trello]](https://trello.com/c/So7Hr7S7)
- Fixed incorrect positioning on _Add Event_ button on the founder dashboard when viewing using mobile devices. [[Trello]](https://trello.com/c/VYd5fqFH)
- Fixed broken styling of the contact form on the `/talent` page. [[Trello]](https://trello.com/c/OwAz4LaG)

## 2017.03.27

- Design and implementation of Stage 1 of switch to subscription model is complete. [[Trello]](https://trello.com/c/r5wuULZ2)
- A service has been created to daily prune the list of users in Intercom to keep costs down. [[Trello]](https://trello.com/c/lBEco17T)
- `Rails.llog` and all related code have been removed. [[Trello]](https://trello.com/c/gh7pcaFX)
- Fixed a crash on founder profile edit page when uploading non-image file as college identification. [[Trello]](https://trello.com/c/8ZXzD8If)
- `en.yml` was cleaned up. [[Trello]](https://trello.com/c/X3Ac3XeA)
- Unused _lita_ handlers were cleaned up. [[Trello]](https://trello.com/c/dmXeSDWB)
- The `Server-Timing` header was added to all responses. [[Trello]](https://trello.com/c/Ag856i6b)
- The version of Ruby used was updated to 2.4.1. [[Trello]](https://trello.com/c/0gEMn3vl)
- All gems were locked to their minor version to allow _safe_ `bundle update`, and all gems were updated. [[Trello]](https://trello.com/c/Irx7Scg2)
- AWS security was improved. [[Trello]](https://trello.com/c/1f4midHS)
- Cloudflare's paid _Polish_ feature was turned on to automatically compress cached images. [[Trello]](https://trello.com/c/nZdODoqS)

## 2017.03.20

- Admin Interface's _User Activity_ list now has a user filter that loads users using AJAX instead of pre-loading. [[Trello]](https://trello.com/c/ePsDNjky)
- Restored a bunch of fields to the Founder profile edit page - they were accidentally removed in an earlier commit. Also added a new field along with the change, required for graduation. [[Trello]](https://trello.com/c/WsZn995T)

## 2017.03.13

- `Startup#show` load times have been cut down by deferring loading of earlier events. [[Trello]](https://trello.com/c/X6BccOYq)
- When a founder gets a new verified timeline event, co-founders are notified by Vocalist of the event. [[Trello]](https://trello.com/c/f2N6yxbY)
- When a SV.CO faculty member edits a timeline event description, the author is notified by Vocalist of the update with a _diff_. [[Trello]](https://trello.com/c/0lKcEILd)
- The `timeline_event_show` route no longer exposed private event data via OG tags. [[Trello]](https://trello.com/c/BGPpmMmS)
- Added name of student to list of columns exported as CSV from AA `QuizAttempts#index`. [[Trello]](https://trello.com/c/O4sLnNLt)
- Fixed an incorrect flash message appearing upon login using OAuth. [[Trello]](https://trello.com/c/BGNC2CNG)
- Fixed an issue with Web visit stats displayed on AA Dashboard. [[Trello]](https://trello.com/c/f82EEldQ)
- All references to the Playbook were removed from the website. [[Trello]](https://trello.com/c/PGcxm9Ut)
- Fixed a crash that occurred when unauthenticated user attempts to access a restricted founder route. [[Trello]](https://trello.com/c/2M0cFvXz)
- Fixed a bug which resulted in AA Founder CSV downloads being empty. [[Trello]](https://trello.com/c/rjjaOc07)
- Fixed a mistake in `VerificationService` in calculating previous points for a target. [[Trello]](https://trello.com/c/aCkEUDnO)
- Rails was upgraded to latest 5.0.2. [[Trello]](https://trello.com/c/ZAIbxeYI)

## 2017.03.06
- `UserActivity` table has been introduced to track free-form activity - currently tracks resource downloads and connect request creation. Trello [[1]](https://trello.com/c/oQRYSyAt)[[2]](https://trello.com/c/0pHSZ2MT)
- Vocalist pings for feedback submission have been restored. [[Trello]](https://trello.com/c/qks1vNwo)
- Founders are now allowed to re-submit targets even after completion. [[Trello]](https://trello.com/c/biQsh8Vj)
- The contact form was removed from `/about/contact` since Intercom is preferred / easier. [[Trello]](https://trello.com/c/Gfsoe6JL)
- Exited founders are now prevented from taking _founder-actions_. [[Trello]](https://trello.com/c/OfWmlTiw)
- Fixed a minor bug in spec for `Batch` that caused it to fail on March 1. [[Trello]](https://trello.com/c/ZtupISoG)
- Updated gem `letter_opener_web` to avoid deprecation warnings. [[Trello]](https://trello.com/c/v7pgrqCK)
- The `PublicSlackTalk` class was refactored to remove multiple (unnecessary) methods of replying to a request. [[Trello]](https://trello.com/c/cJD4yDJR)
- Some stale code related to `VerificationService` was removed. [[Trello]](https://trello.com/c/2YGWAfZA)
- Ahoy's logs now store the logged in `User` insted of `Founder`. [[Trello]](https://trello.com/c/ioJFRJbV)
- Removed the `auto_verified` flag from `Target` and all related code. [[Trello]](https://trello.com/c/KSAjU4hZ)


## 2017.02.27

- The timeline events review interface has undergone multiple upgrades. Trello. [[1]](https://trello.com/c/Bb5BlFQK)[[2]](https://trello.com/c/KKzA5SrC)[[3]](https://trello.com/c/nLaVTALZ)[[4]](https://trello.com/c/TVWC7SZx)
- The startup feedback mailer sent out when faculty adds feedback for a startup was broken - this has been fixed. [[Trello]](https://trello.com/c/lPXWuq06)
- A link to startup's timeline page has been added to AA's CSV export of startups. [[Trello]](https://trello.com/c/gdyp76ZX)
- `Startup#calculated_iteration` has been removed in favor of the stored `iteration` column. [[Trello]](https://trello.com/c/Y68bAd0B)
- We no longer list exited founders on front-end pages. There's a follow up task related to this to block them from accessing founder-actions. [[Trello]](https://trello.com/c/tlGy0axx)
- Fixed a crash in the startup edit form, caused by the presence of a startup category that was duplicated. [[Trello]](https://trello.com/c/n6ujXMNw)
- Fixed a bug in a header animation on the `/talent` page. [[Trello]](https://trello.com/c/7JTGGHsi)
- Added server-side validation for Founder's avatar image file-type - this prevents a crash if a founder attempts to upload non-image files. [[Trello]](https://trello.com/c/U187opW5)
- A basic spec was added for the `/startups/:slug/:event_title/:id` route. [[Trello]](https://trello.com/c/msk7KWXi)
- A `video_embed` field was added to `Resource` - this allows for already uploaded YT videos to be used on the resource page, instead of having to upload the video again to our S3 store. [[Trello]](https://trello.com/c/Wonoaifv)
- Fixed a bug in the `Ability` class where it was checking ability against impersonated user instead of true user. [[Trello]](https://trello.com/c/lWiH9kme)
- Rollbar now reports using `true_user` instead of the impersonated user. [[Trello]](https://trello.com/c/tgKZOgiJ)
- All old / stale React components were removed. [[Trello]](https://trello.com/c/adVovmuE)
- The unused `review_test_embed` field was removed from `Target`. [[Trello]](https://trello.com/c/uIusJgnY)
- The rating titles for faculty connect requests were updated to reduce confusion about their purpose. [[Trello]](https://trello.com/c/VRTIefOl)
- The stale polymorphic assignee field was removed from `Target`. [[Trello]](https://trello.com/c/Y7ckhAZd)
- OAuth exceptions which occur while attempting to post a timeline event to a founder's wall are now handled by disconnecting the user, instead of just crashing. [[Trello]](https://trello.com/c/yoHUWCIF)

## 2017.02.21

- A timeline events review interface for admins has been deployed. [[Trello]](https://trello.com/c/mfPTX78v)
- A roadmap for implementation of Stage 1 of subscription model was built. [[Trello]](https://trello.com/c/tnocfHyM)
- An issue with the Leaderboard, which caused its results for the past week to change has been resolved. [[Trello]](https://trello.com/c/z4rKABRx)
- A time-related bug in `performance_service_spec.rb` was resolved. [[Trello]](https://trello.com/c/43YAIv1R)
- The invite form to SV.CO's Public Slack at `/about/slack` was broken due to changes in Slack policy - this has been fixed. [[Trello]](https://trello.com/c/WbRnbcxu)
- The platform now runs of Ruby's latest version - 2.4.0. [[Trello]](https://trello.com/c/EaGs2y6L)
- MSP coupons are now restricted to specific email addresses. [[Trello]](https://trello.com/c/Fg63StTw)
- Closed a hole which allowed multiple karma point entries to exist for the same team target. [[Trello]](https://trello.com/c/TbfTPgSC)

## 2017.02.13

- Coupons for application fee has been implemented. [[Trello]](https://trello.com/c/DXWCTAQ9)
- Admissions Dashboard on admin interface has been fixed. [[Trello]](https://trello.com/c/2mvrHSEX)
- The `IntercomUserUpdateService` has been removed. [[Trello]](https://trello.com/c/o6xekZ8S)
- The performance of Founder dashboard has been greatly improved. [[Trello]](https://trello.com/c/z3Fbdaar)
- The `AdmissionStatsNotificationJob` has been reinstated after updates to make it work with application rounds. [[Trello]](https://trello.com/c/cm4MUQUN)
- Fixed an issue with `AdmissionStatsService` which caused it to report same startups / founders for multiple statuses per target. [[Trello]](https://trello.com/c/xARzgOzK)
- Fixed a bug related to the Founder edit form which rendered Vocalist unable to ping founders on Slack. [[Trello]](https://trello.com/c/1RD10gc0)
- Authenticity token errors are now managed by resetting session - this should reduce (eliminate, really) instances of users seeing related exceptions. [[Trello]](https://trello.com/c/bJmoTE3O)
- Admissions dashboard on the admin interface has been fixed to work with application rounds. [[Trello]](https://trello.com/c/2mvrHSEX)
- The Targets index page on admin interface has been sped up by trimming available filters. [[Trello]](https://trello.com/c/Of3r5UlI)
- The link to share timeline event in admin interface has been updated to latest standard. [[Trello]](https://trello.com/c/mtSHHst7)
- The leaderboard now correctly calculates the rank for startups without points for a week, when there is more than one startup sharing a rank placed above them. [[Trello]](https://trello.com/c/lruqHGQi)
- Fixed a minor mismatch in margins on Target descriptions on the Founder dashboard. [[Trello]](https://trello.com/c/W33CrzP9)
- Round-specific columns were removed from `Batch` table. [[Trello]](https://trello.com/c/IPsQRkC9)
- Fixed a bug on the Founder dashboard causing filters to display targets that did not fit its criteria. [[Trello]](https://trello.com/c/UFPJXcDs)
- Fixed a crash that occurred when founders from earlier batches visited their dashboard page. [[Trello]](https://trello.com/c/UqeGUed9)
- Fixed a failure of specs for payment stage by introducing `observable_redirect_to`. [[Trello]](https://trello.com/c/ufObIMyk)
- Updated the `/jobs` route to check if logged in user had a corresponding super-admin entry to allow access. [[Trello]](https://trello.com/c/lTs9nfiQ)
- All references to a floating header (top-menu) have been removed. [[Trello]](https://trello.com/c/G96vAaRt)

## 2017.02.06

- The Leaderboard has been updated to show delta from past position. This update applies to page on the website public page, Vocalist's response, and admin leaderboard page. [[Trello]](https://trello.com/c/RQtl703K)
- The icon for website was broken on the submitted-state page for coding stage of application process. [[Trello]](https://trello.com/c/7OAbTHyq)
- `ApplicationStage#testing_stage` has been excised now that it has been replaced by two separate stages. [[Trello]](https://trello.com/c/2ZvDk5BO)
- Overall percentile score and mention of cutoff percentile scores have been removed. We still display percentile score for a stage - this should be worked on later. [[Trello]](https://trello.com/c/CNbIz6my)
- `/about/slack` was displaying a missing app error from Heroku. The `slackin` app has been recreated using `hosting@sv.co` on Heroku, and the new instance is now being used. [[Trello]](https://trello.com/c/YyeOwd66)
- Timeline events linked to targets now prefix description with information about the target. [[Trello]](https://trello.com/c/6S846QRQ)
- When responding to leaderboard requests, Vocalist now includes the time frame for which the leaderboard was generated. [[Trello]](https://trello.com/c/D8mKg7Xc)
- Fixed uneven spacing between bullet points and paragraphs in target descriptions. [[Trello]](https://trello.com/c/miaS1Ppm)

## 2017.01.30

- Application rounds for application process has been deployed. [[Trello]](https://trello.com/c/pUZ1cfBW)
- A brand new screening stage (initial stage) for application process has been implemented. [[Trello]](https://trello.com/c/rCMyzKia)
- The founder edit page now has a single unified form. [[Trello]](https://trello.com/c/2LR1zNne)
- Admin Users can now impersonate any regular user - basically sign in as users and see what they see, do what they can do. [[Trello]](https://trello.com/c/i25kcRNu)
- The separate login process for Admin users has been removed in favor of main site's login. Single sign-on FTW. [[Trello]](https://trello.com/c/eTm2QN2l)
- More partners have been added to the front-page. Trello. [[1]](https://trello.com/c/mIG2hUPp) [[2]](https://trello.com/c/f6H6XuQK)
- The submit feedback form's horizontal resize ability has been removed to prevent display bugs. [[Trello]](https://trello.com/c/L1xv5jj8)
- The option to change team lead for a startup from the admin interface was broken. This has been fixed and updated. [[Trello]](https://trello.com/c/ivwpQ34a)
- The submit feedback form was inaccessible when viewed from the home page - its styling was also broken. Both these issues have been fixed. [[Trello]](https://trello.com/c/1J1xeKSm)
- Sum of karma points have been added to admin interface's Founder#index page. [[Trello]](https://trello.com/c/Sp7qqAxB)
- More information was added to Founder CSV export from admin interface. Also, the index table can now be sorted by product_name. [[Trello]](https://trello.com/c/genrJ118)
- JS error checking has been restored to Talent form spec. [[Trello]](https://trello.com/c/gOGxftPO)
- `EmailBounceValidatable` is now used in the MOOC Registration form. [[Trello]](https://trello.com/c/Iq7rwMLp)
- A bunch of old, unused partials related to homepage were removed. [[Trello]](https://trello.com/c/0O2iLAZW)

## 2017.01.23

- Added ability to filter targets on the Founder Dashboard. [[Trello]](https://trello.com/c/TImTvbU3)
- We've (possibly) fixed a timing bug in the leaderboard generation service - specs related to this have also been improved. [[Trello]](https://trello.com/c/ouvsGOmc)
- Integration with PayTM was tested successfully. The code related to this will be kept in the repository for future use (if required). [[Trello]](https://trello.com/c/OAQoefbY)
- Timeline event descriptions no longer ignore line-breaks when being displayed in the startup timeline and in the admin interface. [[Trello]](https://trello.com/c/jhiglpQl)
- `BaseService` has been removed and its functionality has been extracted into _concens_. [[Trello]](https://trello.com/c/cA4Fd5Oo)
- The _Share on Facebook_ feature has been disabled (silently) for Founder-specific events. [[Trello]](https://trello.com/c/MnjtJKyb)
- Intercom now correctly fetches user details from the `User` model. [[Trello]](https://trello.com/c/XjBqXvDL)
- `Founders::TargetFilterService` and `Targets::DueDateService` have been spec-d. [[Trello]](https://trello.com/c/RFlWtEAZ)
- The application registration form now blocks emails that have previously bounced. [[Trello]](https://trello.com/c/Ha9zA4V2)
- The sign-in form now blocks and informs users if the email address their has previously bounced. [[Trello]](https://trello.com/c/SYBKrT60)
- `User.email_bounced` boolean column has been removed in favor of using `User.email_bounced_at` to perform the same check. [[Trello]](https://trello.com/c/8wniFfnY)

## 2017.01.16

- Feature to connect facebook account to founder profile, for auto-posting timeline events to FB wall has been launched. [[Trello]](https://trello.com/c/y83pIThP)
- MOOC Registration now uses colleges table instead of old universities table. [[Trello]](https://trello.com/c/fk9GaeVV)
- Fixed a bug in the positioning of cards on startups page. [[Trello]](https://trello.com/c/zyaPvvEq)
- Batch Applicant now uses User model for login. [[Trello]](https://trello.com/c/B5dZ1SlR)
- Fixed a bug preventing Vocalist from sending learderboard to channels. [[Trello]](https://trello.com/c/loMy4bs5)
- Updated Vocalist message, removing note about sent email since it was disabled. [[Trello]](https://trello.com/c/htAkuS4v)
- Updated the targets overview page to target stats only on demand. [[Trello]](https://trello.com/c/NRgFwgU1)
- Updated the targets overview page to display list of assignees for a target stat when one particular figure is clicked. [[Trello]](https://trello.com/c/iumFHDBD)
- Timeline event description limit was increased to 500 characters. [[Trello]](https://trello.com/c/tnY587i6)
- Timeline builder submit verification was updated to check for selected file even if file form is closed. [[Trello]](https://trello.com/c/cv1m1u1S)
- `batch_id` was removed from `Target`. This prevents mismatch in batch between target's batch and its program week's batch. [[Trello]](https://trello.com/c/r0EqxTuV)
- Fixed a bug in performance service which caused high-performing starts to show as low-performers. [[Trello]](https://trello.com/c/G7zXa0zq)

## 2017.01.09

- Timeline builder is complete. [[Trello]](https://trello.com/c/EvCvyGdH)
- Lots of content changes. Trello [[1]](https://trello.com/c/wVg6rab5) [[2]](https://trello.com/c/wUewbsDu) [[3]](https://trello.com/c/srYlal5g) [[4]](https://trello.com/c/7sJxQd0U) [[5]](https://trello.com/c/GYYWxHko) [[6]](https://trello.com/c/mVaE6Wth) [[7]](https://trello.com/c/gtxUrA9R) [[8]](https://trello.com/c/t05hkC54)
- There was a minor mismatch between length validation of timeline event description on the client and the server, which caused issues when max-ed out length was submitted. Some slack has been added to prevent any further issues. [[Trello]](https://trello.com/c/CQphNlXs)
- The _Not Improved_ scope for Timeline Events on the admin interface has been rebuilt to work properly with latest data. A timeline builder submission now automatically links itself to previous event needing improvement, if one exists. [[Trello]](https://trello.com/c/T8fVAC24)
- Videos in the dashboard target slides no longer continue to play after being closed. [[Trello]](https://trello.com/c/TWXJAzwA)
- The count of participating universities shown on the home page was stuck at zero. The calculation has been fixed to match latest data. [[Trello]](https://trello.com/c/PR0EXJ1D)
- A confirmed faculty connect request now successfully creates a Google Calendar event - it wasn't working because of an authorization issue. [[Trello]](https://trello.com/c/6yUBp5pH)
- All buttons on the timeline builder action bar are now disabled once the submission process begins. [[Trello]](https://trello.com/c/38FrxweH)
- When submitting a timeline event with a file or a link, clicking the submit button now runs validations on an open file or link form, to ensure that any currently entered values are not missed out when sending data to the server. [[Trello]](https://trello.com/c/3BTo76cs)
- Link Target form in the admin interface for a Timeline event was broken. [[Trello]](https://trello.com/c/v3ImB3e0)
- Removed case-sensitivity from timeline builder's cover image file selector. This allows users to pick files with all-caps file extensions. [[Trello]](https://trello.com/c/URwxeKLL)
- Timeline builder now trims the description to calculate its length and before sending it to the server. [[Trello]](https://trello.com/c/bA9ucMxX)
- Karma Points are now automatically awarded upon verification of timeline event, based on assigned grade. [[Trello]](https://trello.com/c/UzeeehnJ)
- Slack username validation on the Founder edit page has been updated to match Slack's latest standard. [[Trello]](https://trello.com/c/1LwnobUQ)
- The Rich text editor used to edit Target descriptions in the admin interface was not displaying list style icons correctly. [[Trello]](https://trello.com/c/j2LY0Lzx)
- Fixed broken tag entry inputs because of recent update to Select2 (to v4). [[Trello]](https://trello.com/c/0OqBuso2)
- Fixed an crash when revisiting the Founder edit page immediately after uploading a new avatar image. [[Trello]](https://trello.com/c/Mv4VIe1Z)
- Clicking the logo after being signed in now leads to founder dashboard page. [[Trello]](https://trello.com/c/WJAnLqqo)
- The timeline builder would not open on Safari when triggered from a target which has a default timeline event type. This was caused by the presence of some ES7 Javascript that Safari couldn't parse. The ES7 segments have been replaced with ES6 for compatibility. [[Trello]](https://trello.com/c/oZn1JHdE)
- Targets can now be sorted within Target groups. [[Trello]](https://trello.com/c/aCExMZx2)
- Automatic email sent after onboarding has been disabled. [[Trello]](https://trello.com/c/nyszoy5p)
- The number of roles available to Founders has been reduced to three. [[Trello]](https://trello.com/c/ChGDeb4c)
- The submit feedback form available to signed-in founders had broken styling. [[Trello]](https://trello.com/c/CdbtrL6w)
- The check (tick) button to the right of file and link form elements in the timeline builder now reads `ADD` to clearly communicate its purpose. [[Trello]](https://trello.com/c/fcqgBO9N)
- The _Download Rubric_ button within targets on the founder dashboard now generate a S3 download link on demand, so as to prevent timeouts. [[Trello]](https://trello.com/c/doUVwdNJ)
- The Faculty weekly slots interface has been updated to prevent members from attempting to delete slots that have a connect request (pending or confirmed) upon them. [[Trello]](https://trello.com/c/gBZVUzqE)
- The sign-up form for the MOOC was broken because selection of state was impossible - caused by recent upgrade of Select2 (to v4). [[Trello]](https://trello.com/c/0tDl9pZf)
- The timeline tour has been replaced with a dashboard tour. [[Trello]](https://trello.com/c/hhelb3p3)

## 2017.01.02

- Start of third batch! We've launched the new Founder Dashboard to the public.
- Added select2 picker for timeline event type on the admin target page. [[Trello]](https://trello.com/c/8CE9D48i)
- Fixed an issue with large image uploads on the timeline builder. Trello. [[1]](https://trello.com/c/6wTNKd3d) [[2]](https://trello.com/c/oJznwasB)
- Added a processing stage for the timeline builder, in between submission and 200 return from server. [[Trello]](https://trello.com/c/h8pwPVq3)
- Faculty slots can by filtered by faculty time on admin interface. [[Trello]](https://trello.com/c/qJDvMAyj)
- Public slack invite was broken when iframe sandboxing was performed. This has been fixed. [[Trello]](https://trello.com/c/WHMGHx4s)
- Founder dashboard specs are in place. [[Trello]](https://trello.com/c/hYu3Wr5E)
- Specs for timeline builder are in place. [[Trello]](https://trello.com/c/IKUxpUhV)
- The knapsack gem has been introduced to correctly split workload on the CI. [[Trello]](https://trello.com/c/Me0cgSES)
- Devise columns were dropped from Founder model. [[Trello]](https://trello.com/c/FlelMOLh)
- Fixed a bunch of crash-situations on production. [[Trello]](https://trello.com/c/0HKcmlwr)
- Coverage report and knapsack are activated only when required. This speeds up testing by ~10%. [[Trello]](https://trello.com/c/ciUQLaRv)

## 2016.12.26

- Founder dashboard's initial design and implementation phase is complete. [[Trello]](https://trello.com/c/sITTzECe)
- Performance overview panel on the Founder dashboard is functional. [[Trello]](https://trello.com/c/86LHvVl7)
- Old timeline builder was removed from the Startup timeline page. [[Trello]](https://trello.com/c/tbiXwK2m)
- A webhook to handle bounce callbacks from Postmark has been implemented. [[Trello]](https://trello.com/c/UBsLzPnf)
- Added a provision to filter batch applicants by application stage and included some extra info to their CSV export. [[Trello]](https://trello.com/c/W9aWWsQn)
- Fixed a flaky StatsService spec. [[Trello]](https://trello.com/c/Av8vIe3D)
- Rails has been upgraded to latest 5.0.1. [[Trello]](https://trello.com/c/Zv06zafp)

## 2016.12.19

- Deployed a new target overview page for revamped program framework. [[Trello]](https://trello.com/c/rPvTRmUT)
- Add a link to view uploaded partnership deed from the stage 4 submission page on active admin. [[Trello]](https://trello.com/c/oW8EqOUU)
- Added a fallback identicon logo for startups, colored according to their auto-generated name. [[Trello]](https://trello.com/c/ihrvZlEZ)
- Automatically select 11:59 PM as time for `ends_at` of a batch's applications stage. [[Trello]](https://trello.com/c/iVD2ztcN)
- Updated address given on the apply page. [[Trello]](https://trello.com/c/fsifLdjl)
- Added some additional validations to Target. [[Trello]](https://trello.com/c/wRtX41Hl)
- Improved how `sequence`-s were used in Factory Girl templates. [[Trello]](https://trello.com/c/fxl9mEAC)
- Added Rails-specific checks to our Rubocop runs. [[Trello]](https://trello.com/c/UkWirRRS)

## 2016.12.12

- Individual users can now be logged out (when they visit the website) from the admin interface using a new _Sign Out At Next Request_ feature on the User page. [[Trello]](https://trello.com/c/qoUXik8V)
- Fixed broken Founder's team member add / edit form. Incorrely applied HTML5 validations were blocking the form from being submitted. [[Trello]](https://trello.com/c/QaiLMzaC)
- The OAuth login method now correctly redirects user to referer path after successful login. [[Trello]](https://trello.com/c/FZTXZICE)
- A signed-in user, registering for MOOC is now taken directly to start page of MOOC, instead of being emailed another login link. [[Trello]](https://trello.com/c/OrtU2aRM)
- The admin interface for creating application submissions now allows for searching of batch application using select2. [[Trello]](https://trello.com/c/y3fTfvmT)
- Removed use of `member_label` option from all Formtastic forms since it has been deprecated. [[Trello]](https://trello.com/c/xQWbKUp6)
- Removed `invited_batch` association from `Founder`. [[Trello]](https://trello.com/c/KSTtTMs5)
- `TargetGroup.number` was renamed to `sort_index` to clarify its purpose. [[Trello]](https://trello.com/c/4yoHu0bz)
- Removed unused `full_validation` accessor from Startup and Founder. [[Trello]](https://trello.com/c/JS9HE4ac)

## 2016.12.05

- Changes to database and admin interface to account for Founder Dashboard and Targets Framework is mostly complete. [[Trello]](https://trello.com/c/1Q0bNMcR)
- Removed the ability for founders to add new founders and remove existing founders from their startup. [[Trello]](https://trello.com/c/Rggpxzqf)
- Founders no longer have to validate their phone numbers - it is freely editable. [[Trello]](https://trello.com/c/A1mM8nP2)
- Password change form was removed from Founder's edit page. [[Trello]](https://trello.com/c/0EG9eMXd)
- Founder edit form has been improved to display filename of existing identification proof. [[Trello]](https://trello.com/c/UDt744bi)
- Incorrect office address on the `/about/contact` page has been updated. [[Trello]](https://trello.com/c/lWlNp20a)
- MOOC Students list on admin interface has been updated to include module completion scopes. [[Trello]](https://trello.com/c/lw1XCmhk)
- Generated partnership deed has been updated to list the team lead as the first in any list. [[Trello]](https://trello.com/c/ceBNV7Ob)
- Content was added to the Stage 5 (completion) page of application process. [[Trello]](https://trello.com/c/i8ZS7KSE)
- Applicant's ID and Address proof are now displayed in the admin interface. [[Trello]](https://trello.com/c/oMKQ8fev)
- Stage 4 forms now display an _Uploading..._ message when the button is disabled after clicking submit. [[Trello]](https://trello.com/c/zZMogPOP)
- Removed unused code related to removal of a startup via user-initiated action. [[Trello]](https://trello.com/c/IkJl3B3g)
- Removed unused `test_background` action from `HomeController`, along with related files. [[Trello]](https://trello.com/c/47enFle3)
- Seeded data for Founders has been updated to match data available at the end of current admission process. [[Trello]](https://trello.com/c/WbFzcOaw)

## 2016.11.29

- Onboaring flow for applicants who have completed the application is online. Trello [[1]](https://trello.com/c/DwPEHw4E) [[2]](https://trello.com/c/OldpCMgw)
- Application fee refund is now applied to another applicant if team lead has scholarship. [[Trello]](https://trello.com/c/1B9R2566)
- `target_templates` table has been removed in favor of using the `targets` table. [[Trello]](https://trello.com/c/bcSLW4JN)
- Fix: Intercom image uploads were broken. [[Trello]](https://trello.com/c/Rr6lDSUo)
- Visual timeline of _CareerKhojj_ was updated. [[Trello]](https://trello.com/c/qH1vLXB4)
- Stage 4 completion pages have a new banner. [[Trello]](https://trello.com/c/4S2tDdf6)
- Seed final stage application and applicants. [[Trello]](https://trello.com/c/ADnDQxrg)
- Admissions Stats notification job now has a basic spec. [[Trello]](https://trello.com/c/verll8rm)
- `BatchApplication#status` now correctly handles _closed_ state applications. [[Trello]](https://trello.com/c/ldDeR6Rz)
- Startups are now created with a _fun name_. [[Trello]](https://trello.com/c/xdmQNNYS)
- Founders do not require registration scopes. [[Trello]](https://trello.com/c/7Bv91hhr)
- Upgrade to Ruby 2.3.3. [[Trello]](https://trello.com/c/5yat3uvI)
- Founder's `first_name` and `last_name` have been merged to new `name`. [[Trello]](https://trello.com/c/yh0Mkfir)
- Content has been added for final stage rejection and expiry pages. [[Trello]](https://trello.com/c/WDJdFd93)

## 2016.11.21

- Admissions page (Stage 4) with forms and dynamic agreement PDF generation has been deployed. [[Trello]](https://trello.com/c/mdaZ6Avq)
- Keynote version of Program Framework is ready. [[Trello]](https://trello.com/c/RGTgUj2U)
- Visual timeline created for CareerKhoj has been added to the MOOC. [[Trello]](https://trello.com/c/DcBksRuo)
- Pre-selection stage flow has been spec-d. Trello [[1]](https://trello.com/c/FfONzln4) [[2]](https://trello.com/c/iufkq6vS)
- Updated filters, removing a broken one from admin interface MOOC students list. [[Trello]](https://trello.com/c/wYw07wxp)
- Project's Ruby has been upgraded to latest 2.3.2. [[Trello]](https://trello.com/c/K2INl9nr)
- Admin interface's Payments listing page has been sped up with N+1 optimization. [[Trello]](https://trello.com/c/mShLs3ZS)
- A bug preventing cofounder addition for swept applications has been squashed. [[Trello]](https://trello.com/c/Kc28MtAp)
- Have switching error monitoring solution from Sentry to Rollbar. [[Trello]](https://trello.com/c/ltZ5Y0Nb)
- Fixed incorrect stat reported by daily admissions stats notifier. [[Trello]](https://trello.com/c/yOZLvkd8)

## 2016.11.14

- Founder login with password has been removed in favor of logging in with OAuth2, or via manual email verification. This unifies login action with MOOC Student's login. Trello [[1]](https://trello.com/c/IEf8UeN8) [[2]](https://trello.com/c/x66SgwzX)
- Added _Microsoft Student Partner_ as reference option on the application form, and replaced reference value for existing _MSP_ applicants. Trello [[1]](https://trello.com/c/hpKY4mAN) [[2]](https://trello.com/c/DF2ymoYd)
- Fixed an issue with rendering list of startup team members in admin interface. Also fixed an crash related to displaying team member information when no avatar was set. [[Trello]](https://trello.com/c/ENZw6nQN)
- Fixed a crash related to manual move of applications from stage 1 to 2, by assigning a default application team size of 2. [[Trello]](https://trello.com/c/1N9LyZEv)
- Fixed namespacing of a few service classes, after policy regarding their naming was updated. [[Trello]](https://trello.com/c/b6QBu9pz)
- Fixed a crash on library page which happened when non-numbers were passed to the `page` parameter. [[Trello]](https://trello.com/c/nnYiThxk)
- Removed unused / old files from `/public`. [[Trello]](https://trello.com/c/OMWtAIQe)

## 2016.11.7

- Added content and illustrations for Module 3 of SixWays MOOC. [[Trello]](https://trello.com/c/rqodMUFn)
- Updated Batch 4 interview dates on /apply. [[Trello]](https://trello.com/c/njy0gqQE)
- Updated information about cutoff percentile and interview dates for Stage 3 of Batch 4. [[Trello]](https://trello.com/c/g9S0sbCf)
- Removed GTU launch page and redirected link from GTU landing page to SixWays registration page. [[Trello]](https://trello.com/c/ai6Eo6c1)
- All error pages now use Bootstrap 4 layout. [[Trello]](https://trello.com/c/U5D2s3bh)
- Refactored `InstamojoController` to avoid deprecation warnings [[Trello]](https://trello.com/c/MsEXOab8)
- Fixed issues with Select2 selectors on Batch application form and Library tag filter form when navigating away from, and returning back to the page. [[Trello]](https://trello.com/c/H3W2vGvt)
- Added some basic statistics about the SixWays MOOC to admin dashboard. [[Trello]](https://trello.com/c/priF7ed2)
- Added information specific to _Microsoft Student Partners_ to apply page. [[Trello]](https://trello.com/c/B9I0hN1t)
- _Devise_ library is now used to authenticate and manage user sessions (only MOOC students for now). [[Trello]](https://trello.com/c/0Sg7XDAD)
- Fix: Admin interface button to load latest Intercom conversations was broken. [[Trello]](https://trello.com/c/o7FwDiLD)
- Fix: View link to Faculty on admin interface was broken. [[Trello]](https://trello.com/c/fL7CSRQ2)
- Lots of little optimizations related to recent upgrade to Rails 5. Trello [[1]](https://trello.com/c/dzniSrm5) [[2]](https://trello.com/c/CVFGwaQ4)
- Fix: Admin interface to edit batch applications were unable to link applicants. [[Trello]](https://trello.com/c/E6NXuItq)
- Fix: Admin interface to create and edit batch applications was loading extremely slowly due to N+1 query issues. [[Trello]](https://trello.com/c/e50wFdhb)
- Added anchor links to fee and FAQ sections on apply page. [[Trello]](https://trello.com/c/xgZK5D30)
- Added co-founder email IDs to admin interface's Batch applicant export feature. [[Trello]](https://trello.com/c/GyK2Esrg)
