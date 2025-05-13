inherit "/room/room";

#include <room_defs.h>

static move(string str) {
  if(!str) 
    str = query_verb();

  if(str=="up" && !(MINES+"tunnel03")->query_rope()) {
    write("You can't go stright up with some kind of support.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(0);
  short_desc = "Tunnel with a hole";
  long_desc =
    "There is a big hole in the ceiling in this section of the "+
    "tunnel. @@extra_look@@\n";

  items = ({
    "tunnel", "It is dark",
    "hole", "It leads up",
    "rope", "@@rope_look@@",
  });

  dest_dir = ({
    MINES + "tunnel14", "east",
    MINES + "tunnel10", "west",
    MINES + "tunnel08", "up",
  });
}

string extra_look() {
  if((MINES+"tunnel03")->query_rope())
    return "There is a rope hanging down from above!";
  return "";
}

string rope_look() {
  if((MINES+"tunnel03")->query_rope())
    return "It is a very sturdy rope and could support your weight";
  return "What ?";
}
