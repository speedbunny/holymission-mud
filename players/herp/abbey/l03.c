#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="The Library Stacks";
     long_desc=
"You are standing in a huge, cavernous storage area for\n"+
"extensive collection of illuminated books, owned by the Abbey.\n";
     dest_dir=({ PATH+"/l02","north",
		 PATH+"/l04","east" });
  }
}

init() {
  ::init();
  add_action("east","east");
}

east() {
  write("You enter the labyrinth, forgetting all worries of getting lost "+
	"forever.\n");
  return ::move("east");
}
