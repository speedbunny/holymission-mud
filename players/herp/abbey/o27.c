#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="West Path";
     long_desc=
"A narrow foothpath hugging the west wall of the abbey.\n";
     dest_dir=({ PATH+"/o02","north",
		 PATH+"/o26","south" });
  }
}
