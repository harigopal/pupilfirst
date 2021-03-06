type t = {
  id: string,
  name: string,
  number: int,
  unlockOn: option(string),
};

let decode = json =>
  Json.Decode.{
    id: json |> field("id", string),
    name: json |> field("name", string),
    number: json |> field("number", int),
    unlockOn:
      json |> field("unlockOn", nullable(string)) |> Js.Null.toOption,
  };

let id = t => t.id;
let name = t => t.name;
let number = t => t.number;
let unlockOn = t => t.unlockOn;

let isLocked = t =>
  switch (t.unlockOn) {
  | Some(date) => date |> DateFns.parseString |> DateFns.isFuture
  | None => false
  };

let sort = levels => levels |> List.sort((x, y) => x.number - y.number);