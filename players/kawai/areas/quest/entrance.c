inherit "room/room";

void reset(int arg)
  {set_light(-4);
  short_desc = "Bloody Hall";
  long_desc ="As you walk, you hear a strange sloshing sound.  Curiously, you look "+
  "down, only to find yourself wading in a pool of blood and body parts.  "+
  "Scrawled in blood, in a messy handwriting are the words DEATH TO "+
  "THOSE WHO DO NOT BELIEVE.  A strange breeze circulates throughout "+
  "the room.\n";
  smell = "The air smells of death and decay.";
 dest_dir = ({"players/kawai/areas/darkpass","leave",
  "players/kawai/areas/quest/intersect","east"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "blood","A pool nearly a foot deep.  You wonder how many people\n"+
  "died for this.",
  "body","No wholes...just parts",
  "bodies","You only find fragments",
  "pool","You wade through a pool of coagulating blood",
  "part","Looks like a foot...",
  "parts","Assorted body parts..."});
  ::reset(arg);
  replace_program("room/room");}
