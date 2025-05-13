#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Bath corridor";
     long_desc=
"You stand in a cold, stone corridor, smelling of unwashed bodies, and\n"+
"surprisingly, sweet bath herbs.  You hear someone moaning nearby.\n";
     dest_dir=({ PATH+"/c06","north",
		 PATH+"/c07","east",
		 PATH+"/c04","west" });
  }
}
