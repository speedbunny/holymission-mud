inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Northern walk";
  long_desc = "You walk down a pleasant little path on the north side "+
  "of the courtyard.  To the west is one of the castle "+
  "gates, and to the east is the palace itself.  Southwards "+
  "you see a beautiful courtyard and statue.\n";
  smell = "The air sweet";
  dest_dir = ({"players/kawai/areas/dwarves/palace/ngate","west",
  "players/kawai/areas/dwarves/palace/nchamber","east",
  "players/kawai/areas/dwarves/palace/centeryard","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "gate","It is a large, guarded gate leading to the courtyard",
  "courtyard","It is beautifully decorated.  In the center is a large statue",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",
  "path","It is of brightly colored cobblestone",
  "cobblestone","The rocks are brightly colored and neatly arranged",
  "rock","What do you think?",
  "rocks","Don't get out much, do you?",
  "statue","It is a large statue of the king....obviously not life-sized",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}



