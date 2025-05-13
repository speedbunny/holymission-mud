inherit "room/room";

void reset(int arg) 
  {short_desc = "Underground passage";
  long_desc = "You are in a dark underground passage.  The air is damp, and a slight breeze "+
  "flows by.  You can hear the roar of a waterfall to the southwest, and feel a "+
  "strange breeze to the east.\n";
  smell = "The air is damp.";
  dest_dir = ({"players/kawai/areas/wcave","southwest",
  "players/kawai/areas/passage1","east"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp"});
  ::reset(arg);
  replace_program("room/room");}
