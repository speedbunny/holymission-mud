inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "new3";
  long_desc = 
        "You are still on the path to Jake's newbie area.\n"
        "The dirt is getting somewhat sandy here.\n";
  items = ({ "dirt", 
 	"Well what does it look like?!?!?!?"+
 	"This DIRT has a very sandy texture to it" });
  DD = ({
   NEW + "new2","south",
   NEW + "new4","east",
   });

replace_program("room/room");
}

