inherit "room/room";

void reset(int arg) 
  {set_light(1);
  short_desc = "Underground river";
  long_desc = "You are deep in an cave formed by the flow of an underground river. "+
  "The water flows swiftly beneath you, and a strange light comes from "+
  "the east.\n";
  smell = "The air is damp and musty.";
  dest_dir = ({"players/kawai/areas/orbcave","east",
  "players/kawai/areas/clifftop","southwest"});
  items = ({"water","It flows swiftly underneath you", 
  "river","It doesn't flow as strong as you once imagined it did, yet you still stumble\n"+
  "as you try to wade through it",
  "light","It comes from an unknown source",
  "cave","It's not very big, and the floor is covered with water"});
  ::reset(arg);
  replace_program("room/room");}
