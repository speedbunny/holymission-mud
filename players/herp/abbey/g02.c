#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Stairwell";
     long_desc=
"You are in a narrow stairwell, hewn roughly from the surrounding rock.\n"+
"An odor of ancient decays assaults you.\n";
     dest_dir=({ PATH+"/g01","up",
		 PATH+"/g03","down" });
  }
}
init() {
  ::init();
  add_action("down","down");
}

down() {
  if (!present("relic",this_player())) {
     write("You dare not to pass without protection.\n");
     return 1;
  }
  /* Make it unsneakable */
  this_player()->move_player("down#"+PATH+"/g03");
  return 1;
}

move(str) { if (str!="down") return ::move(str); }
