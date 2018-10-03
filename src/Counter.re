/* My implementation for redux Counter */

type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle;

let component = ReasonReact.reducerComponent("Counter");

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
    let message = "Clicks: " ++ string_of_int(self.state.count);
    <div>
      {
        if (self.state.show) {
          <button onClick={send'(self, Click)}>
            {ReasonReact.string(message)}
          </button>;
        } else {
          ReasonReact.null;
        }
      }
      <button onClick={send'(self, Toggle)}>
        {ReasonReact.string("Toggle")}
      </button>
    </div>;
  },
};