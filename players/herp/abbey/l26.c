inherit "room/room";
#include "abbey.h"
#include "lab.h"

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A room in the labyrinth";
     long_desc=
"You are in a normal size room somewhere in the labyrinth.\n"+
"The walls are lined with shelves, and at least one book is\n"+
"on each shelf.\n";
     dest_dir=({ PATH+"/l24","down",
		 PATH+"/l28","eastdown" });
  }
}
