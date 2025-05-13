inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Eastern tower";
  long_desc = 
    "You arrived in the eastern tower inside the castle of `Worlds of Wonder`.\n"+
    "Stairs are going up and down before you, but you feel that going up will\n"+
    "be very dangerous. Hold on and think what to do, before you do something\n"+
    "that will not be the best to do ...\n";
  dest_dir = ({
    "/players/jug/room/floor_east.c", "west",
    "/players/jug/room/cellar_stairs.c", "down",
  });
replace_program("room/room");
}
