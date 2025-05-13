inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are in a small alcove, and a road leads north here back to the "+
  "main street.  To the east is a small cabin from which you hear "+
  "the frequent clang of a smith hard at work.  To the west is a "+
  "small home, and to the south, a small, but strange hut.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/smith","east",
  "players/kawai/areas/dwarves/village13","north",
  "players/kawai/areas/dwarves/alch","south",
  "players/kawai/areas/dwarves/farm","west"});
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
  "east building","It appears to be a smith's workshop",
  "west building","It appears to be somebody's home",
  "cabin","From within you can hear the hammering of metal",
  "south building","You peek through the window and see an alchemist experimenting",
  "hut","You peek through the window and see an alchemist experimenting",
  "window","Duh...",
  "alchemist","He experiments with various materials, trying to change them from\n"+
  "one form to another",
  "materials","You're not sure what he is doing",
  "building","Which one?  The east, west, or south building?"});
  ::reset(arg);
  replace_program("room/room");}
