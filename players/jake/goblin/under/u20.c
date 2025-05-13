inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "An unfinished tunnel";
 long_desc  = "You stand in a small room carved into the earth.  It appears that\n" +
              "at one time someone wanted to make a tunnel in this direction, but\n" +
              "abandoned the effort for some unknown reason.\n";
 DD = ({
     UN + "u1","north",
     });
replace_program("room/room");
}
