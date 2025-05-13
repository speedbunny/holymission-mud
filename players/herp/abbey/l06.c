#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room in the labyrinth";
     long_desc=
"You are in a smaller room somewhere in the labyrinth.\n" +
"The book shelves on the wall are empty here.\n";
     dest_dir=({ PATH+"/l05","south",
		 PATH+"/l08","northwest",
		 PATH+"/l09","up",
		 PATH+"/l07","east" });
  }
}
