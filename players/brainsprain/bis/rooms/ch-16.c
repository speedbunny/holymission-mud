inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "Bismarck Hall";
  long_desc =
"There are only a few braziers here to light your way.  A few rag-tag "+
"peasants shuffle down the hall muttering obscenities about the count's "+
"unfair treatment of his citizens.  A red carpet runs the length of the room.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-17.c","east",
    br+"/ch-15.c","west",
  });
items = ({
  "hall",
  "The northern hall",
  "carpet",
  "The red carpet of welcome",
  "braziers",
  "Metal torches",
  "citizens",
  "Foul smelling dissidents of the land",
  "peasants",
  "Foul smelling dissidents of the land",
});
::reset(arg);
  replace_program("room/room");

}
