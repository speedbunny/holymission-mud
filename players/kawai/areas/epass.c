inherit "room/room";

void reset(int arg)
  {short_desc = "Underground passage";
  long_desc = "You are in a dark underground passage.  The air is damp, and a slight breeze "+
  "flows by.  You can hear the sound of water far to the west.   You feel a "+
  "strange breeze to the southeast.\n";
  smell = "The air is damp.";
  dest_dir = ({"players/kawai/areas/darkpass","southeast",
  "players/kawai/areas/passage1","west"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp", 
  "water","You can only hear it in the distance",
  "wind","If there were trees, maybe they would rustle, but you're in a cave",
  "west","It is too dark to see that way"
  "breeze","If there were trees, maybe they would rustle, but you're in a cave",
  "southeast","It is too dark to see that way"});
  ::reset(arg);
  replace_program("room/room");}
