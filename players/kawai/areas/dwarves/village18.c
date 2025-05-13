inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are walking down a road in Dwarf City.  Roads lead east-west, and "+
  "a two buildings stand to to either side, north and south, although "+
  "there are no entrances for either one from here.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village13","west",
  "players/kawai/areas/dwarves/village26","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "village","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "dwarves","Various dwarves wander the streets, doing their daily routine",
  "dwarf","A small dwarf runs by with a sling and smacks you with a stone!  Ouch!",
  "city","The dwarf city is busy with dwarves at work, and little ones at play",
  "town","While the buildings are not tall, they do prevent you from seeing the\n"+
  "majority of the city.  As you look around, however, an occasional dwarf passes\n"+
  "or sticks a head out a window",
  "buildings","They all look alike in this section",
  "north building","Seeing no entrance, you can't determine its nature",
  "south building","Although you see no entrance here, you do hear the constant clanging\n"+
  "of a smith hard at work",
  "building","Which one?  The north or south building?"});
  ::reset(arg);
  replace_program("room/room");}
