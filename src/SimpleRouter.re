type route =
  | Home
  | Counter
  | Headlines
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
  | ["counter"] => Counter
  | ["headlines"] => Headlines
  | _ => NotFound
  };

let make = _children => {
  ...component,
  reducer,
  initialState: () => {route: Home},
  didMount: self => {
    let watcherId =
      ReasonReact.Router.watchUrl(url =>
        self.send(ChangeRoute(url->mapUrlToRoute))
      );

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: self =>
    <div className="m-3">
      <ul className="list-reset flex">
        <li className="mr-6">
          <Link className="text-blue hover:text-blue-darker" href="/">
            {ReasonReact.string("Home")}
          </Link>
        </li>
        <li className="mr-6">
          <Link className="text-blue hover:text-blue-darker" href="/headlines">
            {ReasonReact.string("Headlines")}
          </Link>
        </li>
        <li className="mr-6">
          <Link className="text-blue hover:text-blue-darker" href="/counter">
            {ReasonReact.string("Counter")}
          </Link>
        </li>
        <li className="mr-6">
          <Link className="text-blue hover:text-blue-darker" href="/404">
            {ReasonReact.string("Not Found")}
          </Link>
        </li>
      </ul>
      <main className="mt-5">
        {
          switch (self.state.route) {
          | Home => <Greeting name="An" />
          | Counter => <Counter />
          | Headlines => <Headlines />
          | NotFound => <h1> {ReasonReact.string("Not Found")} </h1>
          }
        }
      </main>
    </div>,
};