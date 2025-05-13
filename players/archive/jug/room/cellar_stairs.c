/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Stairs to the cellar";
  long_desc = 
    "Going down, this staircase will bring you to the catacombs of the castle.\n";
  dest_dir = ({
    "/players/jug/room/tower_east.c", "up",
    "/players/jug/room/cellar1.c", "down",
  });
replace_program("room/room");
}
