inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Wheat field";
  long_desc = "You're lost somewhere in the middle of a large wheat field.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/field4","east",
  "players/kawai/areas/dwarves/field5","south",
  "players/kawai/areas/dwarves/field8","north",
  "players/kawai/areas/dwarves/field3","west"});
  items = ({"cave","It is large and illuminated by a strange source",
  "wheat","It's rather tall and blocks your view."});
  ::reset(arg);
  replace_program("room/room");}



