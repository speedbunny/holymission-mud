inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Forest";
    long_desc =
"The trees here are covered in frost and snow. A winding path\n"+
"leading north has been trampled by LARGE feet.\n";
    dest_dir = ({
"players/ted/cold/frost_giant", "north",
"players/ted/cold/ice_path", "south"
    });
  }
}
