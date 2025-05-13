#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room in the labyrinth";
     long_desc=
"You are in a room somewhere in the labyrinth.\n"+
"Books of all sorts line the walls on bookshelves here.\n";
     dest_dir=({ PATH+"/l10","down",
		 PATH+"/l09","southwest",
		 PATH+"/l18","up",
		 PATH+"/l19","northwest" });
  }
}
