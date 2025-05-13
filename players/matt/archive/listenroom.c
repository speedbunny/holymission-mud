inherit "/room/room";

#include "/players/matt/defs.h"

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Shadow testing room";
  long_desc = "This is a room for testing the listen shadow.\n";
}

void init() {
  ::init();
  if(interactive(TP)) {
    add_action("rshad", "rshad");
    (CLONE(PATH + "test/listenshad"))->start_shad(TP);
  }
}
  
int rshad() {
  object shad;
  shad = shadow(TP, 0);
  if(shad) {
    destruct(shad);
    write("Shadow dested.\n");
    return 1;
  }
  write("No shadow detected.\n");
  return 1;
}

void exit(object obj) {
  object shad;
  if(obj && interactive(obj)) {
    shad = shadow(obj, 0);
    if(shad) destruct(shad);
    TELL(obj, "DEBUG: Shadow dested.\n");
  }
}
