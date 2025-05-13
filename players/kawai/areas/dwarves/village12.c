inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead east-west, and "+
  "a two buildings stand to to either side, north and south, although "+
  "there are no entrances for either one from here.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village10","west",
  "players/kawai/areas/dwarves/village20","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "buildings","You are in a slightly more active section of the town.  As you look around\n"+
  "you occasionally see a dwarf walk on by, minding their own business",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs by with a sling and smacks you with a stone!  Ouch!",
  "city","The dwarf city is busy with dwarves at work, and little ones at play",
  "village","The dwarf city is busy with dwarves at work, and little ones at play",
  "town","The dwarf city is busy with dwarves at work, and little ones at play",
  "north building","Peering in through a window, you get the feeling it is a shop",
  "window","A hole in a building...what did you expect?",
  "south building","You can't see much from here",
  "road","It is heavily traveled",
  "building","Which one? The north or south building?"});
  ::reset(arg);
  replace_program("room/room");}



