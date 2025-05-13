inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
  short_desc = "Frozen Path";
  long_desc =
"Snow and ice cover the hills and forests to\n"+
"either side of the path. To the north is deep\n"+
"snow covered forest, while to the south can be\n"+
"seen a snow covered stream. To the west lies a\n"+
"mountain of ice.\n";
    dest_dir = ({
"players/ted/cold/frozen_forest", "north",
"players/ted/cold/ice_south", "south",
"players/ted/cold/ice_path2", "west",
"players/ted/cold/cold_path2", "east"
    });
  }
}
