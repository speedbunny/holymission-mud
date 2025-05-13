/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A floor";
  long_desc = 
    "This is the floor going east to the base of the eastern tower.\n"+
    "There are very expensive lamps on the walls to the right and\n"+
    "left of you, illuminating your way.\n";
  dest_dir = ({
    "/players/jug/room/tower_east.c", "east",
    "/players/jug/room/entryhall", "west",
  });
replace_program("room/room");
}
