type t = {
  id: int,
  name: string,
  avatarUrl: string,
};

let name = t => t.name;
let avatarUrl = t => t.avatarUrl;
let id = t => t.id;

let decode = json =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
    avatarUrl: json |> field("avatarUrl", string),
  };
