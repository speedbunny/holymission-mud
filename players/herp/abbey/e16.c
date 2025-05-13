#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="On the Steps";
     long_desc=
"You stand on wide, stone steps overlooking the abbey courtyard the north.\n" +
"To your south is the chapel, from which you hear singing.\n";
     dest_dir=({ PATH+"/e15","north",
		 PATH+"/e17","south" });
  }
}
