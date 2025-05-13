inherit "room/room";
#include "/players/jake/defs.h"

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "gard10";
    long_desc = 
    "Welcome to Jake's garden.\n"
    "This area is designed for newbies.\n"
    "If you are below level 10 you may procede north.  If not, GO AWAY!\n"
    "Thank you.\n";
    DD = ({
      NEW + "new7","south",
      "/players/jake/newbie/gard9","north",
    });
}

move(arg) {
    if(query_verb()=="north" && TP->query_level()>10 && !TP->query_immortal()) {
	write("You are too powerful to enter this area!\n");
	return 1;
    }
  return ::move(arg);
}
