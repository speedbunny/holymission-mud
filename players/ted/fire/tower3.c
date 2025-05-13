inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "End of Hall";
    long_desc =
"You are at the end of a short hallway. Doors lead\n"+
"east and west.\n";
    dest_dir = ({
"players/ted/fire/tower2", "north",
"players/ted/fire/tower_capt", "west",
"players/ted/fire/tower_sarg", "east"
    });
  }
}
