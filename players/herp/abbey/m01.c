#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Southern Courtyard";
     long_desc=
"You are in the southern section of the courtyard.  To your southeast you hear\n"+
"cries of pain and see a graveyard.  To your south you hear the monks singing\n"+
"hymns in the chapel.\n";
     dest_dir=({ PATH+"/e15","west",
		 PATH+"/m02","east" });
  }
}
