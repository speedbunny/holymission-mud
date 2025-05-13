
#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="A Small Empty Room";
     long_desc=
"An empty room.  It looks like someone has been here recently\n"+
"because there is no dust.\n";
     dest_dir=({ PATH+"/s06","west" });
  }
}
