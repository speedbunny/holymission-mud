#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Bath corridor";
     long_desc=
"You are in a stone corridor.  It is cold and wet, and smells of molds.\n"+
"You see footprints going in all directions.\n";
     dest_dir=({ PATH+"/c10","north",
		 PATH+"/c11","east",
		 PATH+"/c07","west" });
  }
}
