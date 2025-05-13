inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Snowy Clearing";
    long_desc =
"The forest ends here and the ice tundra starts. As far\n"+
"as the eye can see is white frozen ice and snow.\n";
    dest_dir = ({
"players/ted/cold/ice_troll", "north",
"players/ted/cold/quaggoth", "west",
"players/ted/cold/ice_elem", "east",
"players/ted/cold/mammoth", "south"
    });
  }
}
