/*Room description corrected by Silas*/

inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark room";
  long_desc = 
    "You entered the catacombs of Worlds of Wonder. Carefully look at\n"+
    "each monster before you kill it, and look for special things ...\n"+
    "Looking down you feel that down there your torch will not be enough to\n"+
    "illuminate the room below !!!\n";
  dest_dir = ({
    "/players/jug/room/cellar_stairs.c", "up",
    "/players/jug/room/cellar2.c", "down",
  });
replace_program("room/room");
}
