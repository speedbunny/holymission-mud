inherit "room/room";

void reset(int arg)
  {set_light(-4);
  short_desc = "Prison Cells";
  long_desc ="You walk down a long hall lined with makeshift prison cells. All are "+
  "full, but all with forgotten, decaying corpses.  While looking around you "+
  "catch a glimpse of something moving in one of the cells further to the east.\n";
  smell = "The air smells of death and decay.";
  dest_dir = ({"players/kawai/areas/quest/intersect","southwest",
  "players/kawai/areas/quest/children","east"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "blood","A pool nearly a foot deep.  You wonder how many people\n"+
  "died for this.",
  "body","No wholes...just parts",
  "bodies","You only find fragments",
  "part","Looks like a foot...",
  "hall","Dozens of makeshift prison cells line the walls, each full of decaying corpses",
  "parts","Assorted body parts...",
  "rune","You can not read them",
  "runes","They are in some archaic language, foreign to you",
  "cell","This one contains the half decayed remains of an elf",
  "cells","Makeshift prison cells",
  "corpse","Looks like a small child",
  "corpses","Many of them old and decaying"});
  ::reset(arg);
  replace_program("room/room");}
