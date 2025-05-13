inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "Heading down the eastern tunnel",
 long_desc  = "Strange noises can be heard from deep within the tunnel.  A small\n" +
              "rat scurries by, as if in a panicked state.  It is hard to see\n" +
              "down the tunnel, and a light source will be needed if you choose\n" +
              "to adventure any further.\n";
 items = ({
  "rat","A small rat.\nHe has already ran by, so you can't see what he looks like",
 });
 DD = ({
  UN + "u1","west",
  UN + "u5","east",
  });
replace_program("room/room");
}
