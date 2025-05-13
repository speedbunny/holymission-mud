inherit "room/room";

void reset(int arg) 
  {set_light(1);
  short_desc = "Dock";
  long_desc = 
  "You stand on a rickety old dock afloat in a swiftly moving river. "+
  "To the north you can return to town.  At this particular point "+
  "in the river, the water flows swiftly, and looks too dangerous to "+
  "enter.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village16","north"});
  items = ({"cave","It is large and illuminated by a strange source",
  "water","It is deep and fast flowing",
  "dock","It isn't very sturdy, and with the river flowing as swiftly as it\n"+
  "is now, you best be moving off",
  "village","You see a small town to the northeast",
  "town","Most of the buildings are off to the north east, but you can't see\n"+
  "much from here",
  "buildings","You can't see anything from out on the dock",
  "building","You can't see anything from out on the dock",                 
  "river","It is a magnificent underground river"});
  ::reset(arg);
  replace_program("room/room");}

