inherit "room/room";

void reset(int arg) 
  {short_desc = "Underground passage";
  long_desc = "You are in a dark underground passage.  The air is damp, and a slight breeze "+
  "flows by.  You can hear the sound of a water to the west, and feel a "+
  "strange breeze to the east.  A tunnel leads upwards here.\n";
  smell = "The air is damp.";
  dest_dir = ({"players/kawai/areas/wpass","west",
  "players/kawai/areas/epass","east",
  "players/kawai/areas/slope3","up"});
  items = ({"cave","It is cold and damp",
  "wind","If there were trees, the leaves might rustle, but you're in a cave",
  "breeze","If there were trees, the leaves might rustle, but you're in a cave",
  "east","The cave is too dark to see much",
  "west","The cave is too dark to see much",
  "up","The cave is too dark to see much",
  "passage","It is cold and damp",
  "tunnel","It leads up, probably to the surface"});
  ::reset(arg);
  replace_program("room/room");}
