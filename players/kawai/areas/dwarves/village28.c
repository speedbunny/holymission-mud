inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are at the eastern part of town, in front of the King's "+
  "palace.  Roads lead north and south from here towards the "+
  "palace's northern and southern gates, respectively.  To the "+
  "west stands a long hall, and a heavy iron fence to the east, "+
  "which blocks passage to the king's courtyard.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/empty2","west",
  "players/kawai/areas/dwarves/village20","north",
  "players/kawai/areas/dwarves/village26","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "road","It is dry and dusty",
  "village","It's such a quaint little town",
  "town","It's a lovely place",
  "city","It's surprisingly quite today",
  "buildings","They all look the same here",               
  "building","It's just an ordinary building",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",
  "fence","It is a heavy iron fence, much to tall to climb over",
  "gate","You can't see much from here",
  "courtyard","It is beautifully decorated.  In the center is a large statue",
  "statue","It is a large statue of the king....obviously not life-sized",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}


