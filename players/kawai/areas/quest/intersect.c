inherit "room/room";

void reset(int arg)
  {set_light(-4);
  short_desc = "Intersection";
  long_desc ="You stand at an intersection in the cave.  Archaic runes are "+
  "scribbled on the walls, and the smell of death makes you "+
  "sick as blood and body parts stain the floor.  "+
  "You hear what may be the screams of children to the northeast.\n";
  smell = "The air smells of death and decay.";
  dest_dir = ({"players/kawai/areas/quest/entrance","west",
  "players/kawai/areas/quest/prison","northeast",
  "players/kawai/areas/quest/anteroom","southeast"});
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "blood","A pool nearly a foot deep.  You wonder how many people\n"+
  "died for this.",
  "body","No wholes...just parts",
  "bodies","You only find fragments",
  "part","Looks like a foot...",
  "parts","Assorted body parts...",
  "wall","Strange runes are scrawled in blood upon the stone walls",
  "walls","Strange runes are scrawled in blood upon the stone walls",
  "rune","You can not read them",
  "runes","They are in some archaic language, foreign to you"});
  ::reset(arg);
  replace_program("room/room");}

