type route =
  | Home
  | NotFound;

type state = {route};

type action =
  | ChangeRoute(route);

let component = ReasonReact.reducerComponent("SimpleRouter");

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [] => Home
  | _ => NotFound
  };

let make = _children => {
  ...component,
  reducer,
  initialState: () => {route: Home},
  didMount: self => {
    let watcherId =
      ReasonReact.Router.watchUrl(url =>
        switch (url.path) {
        | ["/"] => self.send(ChangeRoute(Home))
        | _ => self.send(ChangeRoute(NotFound))
        }
      );

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: self =>
    switch (self.state.route) {
    | Home =>
      <div>
        <Greeting name="An" />
        <Button onClick=(_e => ReasonReact.Router.push("/whatever"))>
          {ReasonReact.string("Change")}
        </Button>
      </div>
    | NotFound => <h1> {ReasonReact.string("Not Found")} </h1>
    },
};