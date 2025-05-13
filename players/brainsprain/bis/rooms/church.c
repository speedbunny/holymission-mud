inherit "room/church";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  short_desc = "The Bismarck Church";
  long_desc =
    "The stained glass frieze depicts the exorcism of a great demon.  The "+
    "high altar is against the far end of the room.  The stark wooden pews "+
    "fill the vastness of the hall.  The chiming of bells can be heard above "+
    "the din of the congregation.  A man preaches fire and brimstone from "+
    "huge stone pulpit.  A massive, golden sword hangs to the left of the "+
    "door.  The rafters of the lofty ceiling are filled with spectators.\n";
  set_light(1);
  dest_dir = ({
    br+"/tr-3.c","east",
  });
  items = ({
    "hall",
    "The Towpath Church",
    "room",
    "The Towpath Church",
    "frieze",
    "A picture of the exorcism of a demon",
    "pulpit",
    "A huge stone lecturn",
    "altar",
    "A golden altar with a sword painted on the drapings",
    "sword",
    "The legendary sword of the demon slayer",
    "rafters",
    "Hefty Oak rafters",
    "man",
    "The preacher",
    "pews",
    "All the pews are full, people are forced to sit in the rafters",
  });  
}
void init(){
  ::init();
  add_action("pray","pray");
  add_action("pray", "regenerate");
}
