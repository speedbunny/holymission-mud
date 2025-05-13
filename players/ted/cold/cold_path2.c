inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Cold Path 2";
    long_desc =
"This path gets colder the farther west you go.\n";
    dest_dir = ({
"players/ted/cold/cold_path", "east",
"players/ted/cold/ice_path", "west"
    });
  }
}
