inherit "room/room";

void reset(int arg) 
  {clone_list=({1,4,"dwarf","players/kawai/monst/sdwarf",0});
  set_light(1);
  short_desc = "Small hut";
  long_desc = 
  "The small hut is decorated in usually dwarven nature--boring... "+
  "The walls are bare, and only a bed and table adorn the room.  Toys "+
  "are scattered about the floor, giving the impression this is a favorite "+
  "place for young dwarves to play.\n";
  smell = "The air is fresh.";
  dest_dir = ({"players/kawai/areas/dwarves/village6","west"});
  items = ({"room","It is rather plain looking",
  "toys","Various dwarven toys...rocks, sticks...nothing interesting",
  "toy","Various dwarven toys...rocks, sticks...nothing interesting",
  "wall","The walls are bare, probably to keep valuables out of the reach of children",
  "hut","You are in it!",
  "walls","The walls are bare, probable to keep valuables out of the reach of children",
  "bed","It doesn't look comfortable",
  "table","An old bedside table"});
  ::reset(arg);
  replace_program("room/room");}



