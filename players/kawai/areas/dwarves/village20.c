inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are at the eastern part of town, in front of the King's "+
  "palace.  To the north is part of the cliff face, and eastwards "+
  "is the northern gate to the palace.  Roads lead west and south.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village12","west",
  "players/kawai/areas/dwarves/village28","south",
  "players/kawai/areas/dwarves/palace/ngate","east"});
  items = ({"cave","It is large and illuminated by a strange source",
  "cliff","The rock is hard and smooth, and certainly to steep to climb",
  "face","The rock is hard and smooth, and certainly to steep to climb",
  "cliff face","The rock is hard and smooth, and certainly to steep to climb",  
  "rock","You aren't sure what kind it is",
  "road","It is dry and dusty",
  "village","It's such a quaint little town",
  "town","It's a lovely place",
  "city","It's surprisingly quite today",
  "buildings","They all look the same here",
  "building","You see nothing special",
  "gate","It is a large, guarded gate leading to the courtyard",
  "courtyard","It is beautifully decorated.  In the center is a large statue",
  "statue","It is a large statue of the king....obviously not life-sized",
  "castle","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though", 
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though"});
  ::reset(arg);
  replace_program("room/room");}
