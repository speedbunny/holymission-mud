#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="West Path";
     long_desc=
"You slip the treacherous ice covered path, reminding you of your\n" +
"mortality.  The path continues north and south.\n";
     dest_dir=({ PATH+"/o27","north",
		 PATH+"/o25","south" });
  }
}
