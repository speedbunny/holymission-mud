inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Path 2";
    long_desc =
"This ice covered path is very slippery.\n"+
"A large mountain of ice towers to the west.\n";
    dest_dir = ({
"players/ted/cold/ice_path", "east",
"players/ted/cold/ice_cave", "west"
    });
  }
}
