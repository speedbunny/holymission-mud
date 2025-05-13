inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Frozen Foothills";
    long_desc =
"You are at the base of a huge mountain of ice.\n"+
"A path winds precariously up the side of the mountain.\n"+
"While a dark cave opening can be seen to the west.\n";
    dest_dir = ({
"players/ted/cold/cold_top", "up",
"players/ted/cold/ice_drag", "west",
"players/ted/cold/ice_path2", "east"
    });
  }
}
