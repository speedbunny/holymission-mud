#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="The Office";
     long_desc=
"You have entered the office of the church recorder, who isn't here\n"+
"right now.  His desk is piled with papers, a black vial, and a book.\n";
     dest_dir=({ PATH+"/e17","west" });
  }
}
