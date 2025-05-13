inherit "room/room";

void reset(int arg) 
  {set_light(0);
  short_desc = "Cave";
  long_desc = "You have entered a small, dark cave.  The slow drip "+
  "of water echos through throughout, and the chirping "+
  "of bats rings loudly.  To the southeast you can hear "+
  "the muffled voices of celebrating dwarves.\n";
  smell = "The air damp and musty";
  dest_dir = ({"players/kawai/areas/dwarves/village26","north",
  "players/kawai/areas/dwarves/village29","southeast"});
  items = ({"cave","It is dark and wet",
  "bats","You can't see them",
  "water","You slosh through puddles",
  "puddle","A tiny pool of water",
  "puddles","Tiny pools of water"});
  ::reset(arg);
  replace_program("room/room");}

