open CoachesSchoolIndex__Types;

exception UnexpectedResponse(int);

let handleApiError =
  [@bs.open]
  (
    fun
    | UnexpectedResponse(code) => code
  );

type state = {
  name: string,
  imageUrl: string,
  email: string,
  title: string,
  linkedinUrl: string,
  public: bool,
  exited: bool,
  connectLink: string,
  notifyForSubmission: bool,
  imageFileName: string,
  dirty: bool,
  saving: bool,
  hasNameError: bool,
  hasTitleError: bool,
  hasEmailError: bool,
  hasLinkedInUrlError: bool,
  hasConnectLinkError: bool,
  affiliation: string,
};

type action =
  | UpdateName(string, bool)
  | UpdateEmail(string, bool)
  | UpdateTitle(string, bool)
  | UpdateLinkedInUrl(string, bool)
  | UpdateConnectLink(string, bool)
  | UpdatePublic(bool)
  | UpdateNotifyForSubmission(bool)
  | UpdateImageFileName(string)
  | UpdateExited(bool)
  | UpdateAffiliation(string)
  | UpdateSaving;

let component = ReasonReact.reducerComponent("SA_Coaches_CoachEditor");

let str = ReasonReact.string;

let updateName = (send, name) => {
  let hasError = name |> String.length < 2;
  send(UpdateName(name, hasError));
};

let updateEmail = (send, email) => {
  let regex = [%re {|/.+@.+\..+/i|}];
  let hasError = !Js.Re.test_(regex, email);
  send(UpdateEmail(email, hasError));
};

let updateTitle = (send, title) => {
  let hasError = title |> String.length < 2;
  send(UpdateTitle(title, hasError));
};

let updateLinkedInUrl = (send, linkedinUrl) => {
  let regex = [%re
    {|/(https?)?:?(\/\/)?(([w]{3}||\w\w)\.)?linkedin.com(\w+:{0,1}\w*@)?(\S+)(:([0-9])+)?(\/|\/([\w#!:.?+=&%@!\-\/]))?/|}
  ];
  let hasError =
    linkedinUrl |> String.length < 1 ?
      false : !Js.Re.test_(regex, linkedinUrl);
  send(UpdateLinkedInUrl(linkedinUrl, hasError));
};

let updateConnectLink = (send, connectLink) => {
  let regex = [%re
    {|/^(http:\/\/www\.|https:\/\/www\.|http:\/\/|https:\/\/)[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/|}
  ];
  let hasError =
    connectLink |> String.length < 1 ?
      false : !Js.Re.test_(regex, connectLink);
  send(UpdateConnectLink(connectLink, hasError));
};

let booleanButtonClasses = selected => {
  let classes = "toggle-button__button";
  classes ++ (selected ? " toggle-button__button--active" : "");
};

let saveDisabled = state =>
  state.hasTitleError
  || state.hasNameError
  || state.hasEmailError
  || state.hasLinkedInUrlError
  || state.hasConnectLinkError
  || !state.dirty
  || state.saving;

let make =
    (~coach, ~closeFormCB, ~updateCoachCB, ~authenticityToken, _children) => {
  ...component,
  initialState: () =>
    switch (coach) {
    | None => {
        name: "",
        imageUrl: "",
        email: "",
        title: "",
        linkedinUrl: "",
        public: false,
        connectLink: "",
        notifyForSubmission: false,
        exited: false,
        dirty: false,
        saving: false,
        hasNameError: false,
        hasEmailError: false,
        hasTitleError: false,
        hasLinkedInUrlError: false,
        hasConnectLinkError: false,
        imageFileName: "",
        affiliation: "",
      }
    | Some(coach) => {
        name: coach |> Coach.name,
        imageUrl: coach |> Coach.imageUrl,
        email: coach |> Coach.email,
        title: coach |> Coach.title,
        linkedinUrl:
          switch (coach |> Coach.linkedinUrl) {
          | Some(linkedinUrl) => linkedinUrl
          | None => ""
          },
        public: coach |> Coach.public,
        connectLink:
          switch (coach |> Coach.connectLink) {
          | Some(connectLink) => connectLink
          | None => ""
          },
        notifyForSubmission: coach |> Coach.notifyForSubmission,
        exited: coach |> Coach.exited,
        dirty: false,
        saving: false,
        hasNameError: false,
        hasEmailError: false,
        hasTitleError: false,
        hasLinkedInUrlError: false,
        hasConnectLinkError: false,
        imageFileName:
          switch (coach |> Coach.imageFileName) {
          | Some(imageFileName) => imageFileName
          | None => ""
          },
        affiliation: coach |> Coach.affiliation |> OptionUtils.toString,
      }
    },
  reducer: (action, state) =>
    switch (action) {
    | UpdateName(name, hasNameError) =>
      ReasonReact.Update({...state, name, hasNameError, dirty: true})
    | UpdateTitle(title, hasTitleError) =>
      ReasonReact.Update({...state, title, hasTitleError, dirty: true})
    | UpdateEmail(email, hasEmailError) =>
      ReasonReact.Update({...state, email, hasEmailError, dirty: true})
    | UpdateLinkedInUrl(linkedinUrl, hasLinkedInUrlError) =>
      ReasonReact.Update({
        ...state,
        linkedinUrl,
        hasLinkedInUrlError,
        dirty: true,
      })
    | UpdateConnectLink(connectLink, hasConnectLinkError) =>
      ReasonReact.Update({
        ...state,
        connectLink,
        hasConnectLinkError,
        dirty: true,
      })
    | UpdatePublic(public) =>
      ReasonReact.Update({...state, public, dirty: true})
    | UpdateNotifyForSubmission(notifyForSubmission) =>
      ReasonReact.Update({...state, notifyForSubmission, dirty: true})
    | UpdateSaving => ReasonReact.Update({...state, saving: !state.saving})
    | UpdateImageFileName(imageFileName) =>
      ReasonReact.Update({...state, imageFileName, dirty: true})
    | UpdateExited(exited) =>
      ReasonReact.Update({...state, exited, dirty: true})
    | UpdateAffiliation(affiliation) =>
      ReasonReact.Update({...state, affiliation, dirty: true})
    },
  render: ({state, send}) => {
    let formId = "coach-create-form";
    let addCoach = json => {
      let id = json |> Json.Decode.(field("id", int));
      let imageUrl = json |> Json.Decode.(field("image_url", string));
      let newCoach =
        Coach.make(
          ~id,
          ~name=state.name,
          ~imageUrl,
          ~email=state.email,
          ~title=state.title,
          ~linkedinUrl=Some(state.linkedinUrl),
          ~public=state.public,
          ~connectLink=Some(state.connectLink),
          ~notifyForSubmission=state.notifyForSubmission,
          ~exited=state.exited,
          ~imageFileName=Some(state.imageFileName),
          ~affiliation=Some(state.affiliation),
        );
      switch (coach) {
      | Some(_) =>
        Notification.success("Success", "Coach updated successfully")
      | None => Notification.success("Success", "Coach created successfully")
      };
      updateCoachCB(newCoach);
      closeFormCB();
    };
    let avatarUploaderText = () =>
      switch (state.imageFileName) {
      | "" => "Upload an avatar"
      | _ => "Replace avatar: " ++ state.imageFileName
      };
    let handleResponseJSON = json => {
      let error =
        json
        |> Json.Decode.(field("error", nullable(string)))
        |> Js.Null.toOption;
      switch (error) {
      | Some(err) =>
        send(UpdateSaving);
        Notification.error("Something went wrong!", err);
      | None => addCoach(json)
      };
    };
    let sendCoach = formData => {
      let endPoint =
        switch (coach) {
        | Some(coach) =>
          "/school/coaches/" ++ (coach |> Coach.id |> string_of_int)
        | None => "/school/coaches/"
        };
      let httpMethod =
        switch (coach) {
        | Some(_coach) => Fetch.Patch
        | None => Fetch.Post
        };
      Js.Promise.(
        Fetch.fetchWithInit(
          endPoint,
          Fetch.RequestInit.make(
            ~method_=httpMethod,
            ~body=Fetch.BodyInit.makeWithFormData(formData),
            ~credentials=Fetch.SameOrigin,
            (),
          ),
        )
        |> then_(response =>
             if (Fetch.Response.ok(response)
                 || Fetch.Response.status(response) == 422) {
               response |> Fetch.Response.json;
             } else {
               Js.Promise.reject(
                 UnexpectedResponse(response |> Fetch.Response.status),
               );
             }
           )
        |> then_(json => handleResponseJSON(json) |> resolve)
        |> catch(error =>
             (
               switch (error |> handleApiError) {
               | Some(code) =>
                 send(UpdateSaving);
                 Notification.error(
                   code |> string_of_int,
                   "Please try again",
                 );
               | None =>
                 send(UpdateSaving);
                 Notification.error(
                   "Something went wrong!",
                   "Please try again",
                 );
               }
             )
             |> resolve
           )
        |> ignore
      );
    };
    let submitForm = event => {
      ReactEvent.Form.preventDefault(event);
      send(UpdateSaving);
      let element = ReactDOMRe._getElementById(formId);
      switch (element) {
      | Some(element) => sendCoach(DomUtils.FormData.create(element))
      | None => ()
      };
    };
    <div className="blanket">
      <div className="drawer-right">
        <div className="drawer-right__close absolute">
          <button
            title="close"
            onClick={_e => closeFormCB()}
            className="flex items-center justify-center bg-white text-gray-600 font-bold py-3 px-5 rounded-l-full rounded-r-none hover:text-gray-700 focus:outline-none mt-4">
            <i className="fas fa-times text-xl" />
          </button>
        </div>
        <div className="drawer-right-form w-full">
          <div className="w-full">
            <div className="mx-auto bg-white">
              <div className="max-w-2xl px-6 pt-5 mx-auto">
                <h5
                  className="uppercase text-center border-b border-gray-400 pb-2">
                  {"Coach Details" |> str}
                </h5>
              </div>
              <form key="xxx" id=formId onSubmit={event => submitForm(event)}>
                <input
                  name="authenticity_token"
                  type_="hidden"
                  value=authenticityToken
                />
                <div className="max-w-2xl px-6 pb-6 mx-auto">
                  <div className="mt-5">
                    <label
                      className="inline-block tracking-wide text-gray-900 text-xs font-semibold"
                      htmlFor="name">
                      {"Name" |> str}
                    </label>
                    <span> {"*" |> str} </span>
                    <input
                      className="appearance-none block w-full bg-white text-gray-800 border border-gray-400 rounded py-3 px-4 mt-2 leading-tight focus:outline-none focus:bg-white focus:border-gray-500"
                      id="name"
                      type_="text"
                      name="faculty[name]"
                      placeholder="Coach Name"
                      value={state.name}
                      onChange={
                        event =>
                          updateName(
                            send,
                            ReactEvent.Form.target(event)##value,
                          )
                      }
                    />
                    <School__InputGroupError.Jsx2
                      message="is not a valid name"
                      active={state.hasNameError}
                    />
                  </div>
                  <div className="mt-5">
                    <label
                      className="inline-block tracking-wide text-xs font-semibold"
                      htmlFor="email">
                      {"Email" |> str}
                    </label>
                    <span> {"*" |> str} </span>
                    <input
                      className="appearance-none block w-full bg-white border border-gray-400 rounded py-3 px-4 mt-2 leading-tight focus:outline-none focus:bg-white focus:border-gray-500"
                      id="email"
                      type_="email"
                      name="faculty[email]"
                      placeholder="Coach email address"
                      value={state.email}
                      onChange={
                        event =>
                          updateEmail(
                            send,
                            ReactEvent.Form.target(event)##value,
                          )
                      }
                    />
                    <School__InputGroupError.Jsx2
                      message="is not a valid email"
                      active={state.hasEmailError}
                    />
                  </div>
                  <div className="mt-5">
                    <label
                      className="inline-block tracking-wide text-xs font-semibold"
                      htmlFor="title">
                      {"Title" |> str}
                    </label>
                    <span> {"*" |> str} </span>
                    <input
                      className="appearance-none block w-full bg-white border border-gray-400 rounded py-3 px-4 mt-2 leading-tight focus:outline-none focus:bg-white focus:border-gray-500"
                      id="title"
                      type_="text"
                      name="faculty[title]"
                      placeholder="Coach Title/Expertise"
                      value={state.title}
                      onChange={
                        event =>
                          updateTitle(
                            send,
                            ReactEvent.Form.target(event)##value,
                          )
                      }
                    />
                    <School__InputGroupError.Jsx2
                      message="is not a valid title"
                      active={state.hasTitleError}
                    />
                  </div>
                  <div className="mt-5">
                    <label
                      className="inline-block tracking-wide text-xs font-semibold"
                      htmlFor="affiliation">
                      {"Affiliation" |> str}
                    </label>
                    <input
                      value={state.affiliation}
                      onChange={
                        event =>
                          send(
                            UpdateAffiliation(
                              ReactEvent.Form.target(event)##value,
                            ),
                          )
                      }
                      className="appearance-none block w-full bg-white border border-gray-400 rounded py-3 px-4 mt-2 leading-tight focus:outline-none focus:bg-white focus:border-gray-500"
                      id="affiliation"
                      name="faculty[affiliation]"
                      type_="text"
                      placeholder="Acme Inc., Acme University, etc."
                    />
                  </div>
                  <div className="mt-5">
                    <label
                      className="inline-block tracking-wide text-xs font-semibold"
                      htmlFor="linkedIn">
                      {"LinkedIn" |> str}
                    </label>
                    <input
                      className="appearance-none block w-full bg-white border border-gray-400 rounded py-3 px-4 mt-2 leading-tight focus:outline-none focus:bg-white focus:border-gray-500"
                      id="linkedIn"
                      type_="text"
                      name="faculty[linkedin_url]"
                      placeholder="LinkedIn Profile URL"
                      value={state.linkedinUrl}
                      onChange={
                        event =>
                          updateLinkedInUrl(
                            send,
                            ReactEvent.Form.target(event)##value,
                          )
                      }
                    />
                    <School__InputGroupError.Jsx2
                      message="is not a valid LinkedIn URL"
                      active={state.hasLinkedInUrlError}
                    />
                  </div>
                  <div className="mt-5">
                    <label
                      className="inline-block tracking-wide text-xs font-semibold"
                      htmlFor="connectLink">
                      {"Connect Link" |> str}
                    </label>
                    <input
                      className="appearance-none block w-full bg-white border border-gray-400 rounded py-3 px-4 mt-2 leading-tight focus:outline-none focus:bg-white focus:border-gray-500"
                      id="connectLink"
                      type_="text"
                      name="faculty[connect_link]"
                      placeholder="Student connect request link for the coach"
                      value={state.connectLink}
                      onChange={
                        event =>
                          updateConnectLink(
                            send,
                            ReactEvent.Form.target(event)##value,
                          )
                      }
                    />
                    <School__InputGroupError.Jsx2
                      message="is not a valid connect url"
                      active={state.hasConnectLinkError}
                    />
                  </div>
                  <div className="mt-5">
                    <div className="flex items-center flex-shrink-0">
                      <label
                        className="block tracking-wide text-xs font-semibold mr-3"
                        htmlFor="evaluated">
                        {"Should the coach profile be public?" |> str}
                      </label>
                      <div
                        id="notification"
                        className="flex flex-shrink-0 rounded-lg overflow-hidden border border-gray-400">
                        <button
                          type_="submit"
                          onClick={
                            _event => {
                              ReactEvent.Mouse.preventDefault(_event);
                              send(UpdatePublic(true));
                            }
                          }
                          name="faculty[public]"
                          value="true"
                          className={booleanButtonClasses(state.public)}>
                          {"Yes" |> str}
                        </button>
                        <button
                          onClick={
                            _event => {
                              ReactEvent.Mouse.preventDefault(_event);
                              send(UpdatePublic(false));
                            }
                          }
                          className={booleanButtonClasses(!state.public)}>
                          {"No" |> str}
                        </button>
                        <input
                          type_="hidden"
                          name="faculty[public]"
                          value={state.public |> string_of_bool}
                        />
                      </div>
                    </div>
                  </div>
                  <div className="mt-5">
                    <div className="flex items-center flex-shrink-0">
                      <label
                        className="block tracking-wide text-xs font-semibold mr-3"
                        htmlFor="evaluated">
                        {
                          "Should the coach be notified of student submissions?"
                          |> str
                        }
                      </label>
                      <div
                        id="notification"
                        className="flex flex-shrink-0 rounded-lg overflow-hidden border border-gray-400">
                        <button
                          onClick={
                            _event => {
                              ReactEvent.Mouse.preventDefault(_event);
                              send(UpdateNotifyForSubmission(true));
                            }
                          }
                          name="faculty[notify_for_submission]"
                          className={
                            booleanButtonClasses(state.notifyForSubmission)
                          }>
                          {"Yes" |> str}
                        </button>
                        <button
                          onClick={
                            _event => {
                              ReactEvent.Mouse.preventDefault(_event);
                              send(UpdateNotifyForSubmission(false));
                            }
                          }
                          className={
                            booleanButtonClasses(!state.notifyForSubmission)
                          }>
                          {"No" |> str}
                        </button>
                        <input
                          type_="hidden"
                          name="faculty[notify_for_submission]"
                          value={state.notifyForSubmission |> string_of_bool}
                        />
                      </div>
                    </div>
                  </div>
                  <div className="mt-5">
                    <label
                      className="block tracking-wide text-xs font-semibold"
                      htmlFor="avatarUploader">
                      {"Avatar" |> str}
                    </label>
                    <input
                      disabled={state.saving}
                      className="hidden"
                      name="faculty[image]"
                      type_="file"
                      id="sa-coach-editor__file-input"
                      required=false
                      multiple=false
                      onChange={
                        event =>
                          send(
                            UpdateImageFileName(
                              ReactEvent.Form.target(event)##files[0]##name,
                            ),
                          )
                      }
                    />
                    <label
                      className="file-input-label mt-2"
                      htmlFor="sa-coach-editor__file-input">
                      <i
                        className="fas fa-upload mr-2 text-gray-600 text-lg"
                      />
                      <span className="truncate">
                        {avatarUploaderText() |> str}
                      </span>
                    </label>
                  </div>
                </div>
                <div className="p-6 bg-gray-200">
                  <div className="max-w-2xl px-6 mx-auto">
                    <div
                      className="flex max-w-2xl w-full justify-between items-center mx-auto">
                      {
                        switch (coach) {
                        | Some(_coach) =>
                          <div className="flex items-center flex-shrink-0">
                            <label
                              className="block tracking-wide  text-xs font-semibold mr-3"
                              htmlFor="evaluated">
                              {"Has the coach left the school?" |> str}
                            </label>
                            <div
                              id="exited"
                              className="flex flex-shrink-0 rounded-lg overflow-hidden border border-gray-400">
                              <button
                                onClick=(
                                  _event => {
                                    ReactEvent.Mouse.preventDefault(_event);
                                    send(UpdateExited(true));
                                  }
                                )
                                name="faculty[exited]"
                                className={booleanButtonClasses(state.exited)}>
                                {"Yes" |> str}
                              </button>
                              <button
                                onClick=(
                                  _event => {
                                    ReactEvent.Mouse.preventDefault(_event);
                                    send(UpdateExited(false));
                                  }
                                )
                                className={
                                  booleanButtonClasses(!state.exited)
                                }>
                                {"No" |> str}
                              </button>
                              <input
                                type_="hidden"
                                name="faculty[exited]"
                                value={state.exited |> string_of_bool}
                              />
                            </div>
                          </div>
                        | None => ReasonReact.null
                        }
                      }
                      {
                        switch (coach) {
                        | Some(_coach) =>
                          <button
                            disabled={saveDisabled(state)}
                            className="w-auto btn btn-large btn-primary">
                            {"Update Coach" |> str}
                          </button>
                        | None =>
                          <button
                            disabled={saveDisabled(state)}
                            className="w-full btn btn-large btn-primary">
                            {"Create Coach" |> str}
                          </button>
                        }
                      }
                    </div>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>;
  },
};
