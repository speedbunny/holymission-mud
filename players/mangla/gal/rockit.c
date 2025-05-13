inherit "/obj/thing";

#include "/players/mangla/defs.h"

#define ROCK "/tools/wizrock"

int _rock() {
  transfer(clone_object(ROCK),TP);
  destruct(TO);
  return 1;
}

void reset(int arg) {

    if(arg) return;
    ::reset();
    set_alias("temp");
    set_weight(0);
}

void init() {

    ::init();
  add_action("_rock", "rock_me");
}

