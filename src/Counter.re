/* My implementation for redux Counter */

type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle;

let component = ReasonReact.reducerComponent("Counter");

let conc = (x, y) => x ++ y;

let send' = (self, action, _e) => self.ReasonReact.send(action);

let make = _children => {
  ...component,
  initialState: () => {count: 0, show: true},
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },
  render: self => {
    let message =
      string_of_int(self.state.count)
      |> conc("click: ")
      |> conc("Howdy good person, you ");

    <div>
      {
        if (self.state.show) {
          <Button onClick={send'(self, Click)}>
            {ReasonReact.string(message)}
          </Button>;
        } else {
          ReasonReact.null;
        }
      }
      <br />
      <br />
      <Button onClick={send'(self, Toggle)}>
        {ReasonReact.string("Toggle")}
      </Button>
    </div>;
  },
};