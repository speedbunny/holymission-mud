inherit "room/room";

void reset(int arg)
  {set_light(1);
  short_desc = "Village road";
  long_desc = "You are at the eastern part of town, in front of the King's "+
  "palace.  Roads lead north and west from here.  To the south "+
  "is the cliff face, although it looks slightly different from "+
  "the rest of the wall.  Eastwards is the southern gate of "+
  "the palace which leads to the courtyard.\n";
  smell = "The air fresh";
  dest_dir = ({"players/kawai/areas/dwarves/village18","west",
  "players/kawai/areas/dwarves/village28","north",
  "players/kawai/areas/dwarves/palace/sgate","east"});
  hidden_dir=({"players/kawai/areas/dwarves/village27","south"});
  items = ({"cave","It is large and illuminated by a strange source",
  "cliff","It looks rather hazy, as if it didn't really exist",
  "face","It looks rather hazy, as if it didn't really exist",
  "cliff face","It looks rather hazy, as if it didn't really exist",
  "fence","It is a heavy iron fence, much to tall to climb over",
  "gate","It is large and well guarded",
  "courtyard","It is beautifully decorated.  In the center is a large statue",
  "statue","It is a large statue of the king....obviously not life-sized",
  "palace","It's the king's palace.  Not very large, but nicely\n"+
  "decorated, though",
  "cliff","Part of the cliff wall looks hazy, as if it weren't really there",
  "rock","Part of the cliff wall looks hazy, as if it weren't really there",});
  ::reset(arg);
  replace_program("room/room");}
