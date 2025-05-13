inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Southern walk";
  long_desc = "You walk down a pleasant little path on the south side "+
  "of the courtyard.  To the west is one of the castle "+
  "gates, and to the east is the palace itself.  Northwards "+
  "you see a beautiful courtyard and statue.\n";
  smell = "The air sweet";
  dest_dir = ({"players/kawai/areas/dwarves/palace/sgate","west",
  "players/kawai/areas/dwarves/palace/schamber","east",
  "players/kawai/areas/dwarves/palace/centeryard","north"});
  items = ({"cave","It is large and illuminated by a strange source",
  "passage","It is small and barely lit",
  "gate","It is a large, guarded gate leading to the courtyard",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",
  "path","It is of brightly colored cobblestone",
  "cobblestone","The rocks are brightly colored and neatly arranged",
  "rock","What do you think?",
  "rocks","Don't get out much, do you?",
  "courtyard","It is beautifully decorated.  In the center is a large statue",
  "statue","It is a large statue of the king....obviously not life-sized",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}
