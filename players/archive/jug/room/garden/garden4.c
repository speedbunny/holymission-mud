/*Room description corrected by Silas*/

inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Royal Garden";
  long_desc = 
    "You are on a path going east. There is a hedge to the north and south.\n"+
    "Left of the path there are flowers in all colors and bees trying to get\n"+
    "their nectar.\n";
     items = ({
     "flowers", "Bright yellows and red flowers swaying with the wind",
     "bees", "Big yellow and black bees fly around collecting nectar",
     });
  dest_dir = ({
    "players/jug/room/garden/garden1", "west",
    "players/jug/room/garden/garden5", "east",
  });
}
