inherit "room/room";
#include "/players/gareth/define.h"

reset(arg) {
   if(!arg) {
    set_light(1);
    short_desc = "Hall Room";
    long_desc = "You are in the middle of the Fighter area.\n"+
         "To the south is a tunnel to the bank. Other things can\n"+
         "be found in the shops located north of here. To the west\n"+
         "is the bar where you can heal :)\n";
    dest_dir = 
        ({
        "/players/gareth/guild/rooms/bar", "west",
        "/players/gareth/guild/rooms/hall", "east",
        "/players/gareth/guild/rooms/weaponry", "north",
        "/room/newbroker", "south",
        });
   }
}
