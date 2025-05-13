#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room in the labyrinth";
     long_desc=
"You are in a large room in the labyrinth somewhere.\n" +
"Book shelves line the walls here.\n";
     dest_dir=({ PATH+"/l05","southwest",
		 PATH+"/l10","up",
		 PATH+"/l06","west" });
  }
}
