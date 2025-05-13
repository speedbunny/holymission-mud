#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Passage";
     long_desc=
"You are in the dimly-lit hallway.  You see an archway to your south.\n"+
"Dust chokes you, and you hear someone coughing from beyond the arch.\n";
     dest_dir=({ PATH+"/r15","north",
		 PATH+"/r17","south" });
  }
}
