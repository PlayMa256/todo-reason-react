let component = ReasonReact.statelessComponent("Page3");
let make = (~title, ~isDone:bool = false, _children) => {
  ...component,
  render: self =>
    <div>
      <span>(ReasonReact.string(title))</span>
      <span>(
        switch(isDone){
          | false => ReasonReact.string("DO IT")
          | true => ReasonReact.string("WHATA SHAME")
        }
      )</span>
    </div>,
};
