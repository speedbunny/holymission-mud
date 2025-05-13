inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "South of Ice Covered Path";
    long_desc =
"To the south can bee seen a frozen stream and a small\n"+
"wooden bridge.\n";
    dest_dir = ({
"players/ted/cold/ice_path", "north",
"players/ted/cold/ice_troll", "south"
    });
  }
}
