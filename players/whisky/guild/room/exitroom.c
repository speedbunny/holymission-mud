

inherit "room/room";
#include "../guild.h"


void reset(int arg) {
     if( !arg ) {
    set_light(1);
    short_desc = "Room with many exits";
   long_desc =
        "You enter a room with many exits, leading to various "+
         "areas of the Holy Mission. There are several "+
         "ways you could go, but luck is with you and "+
         "wild adventures will follow.\n";
    items = ({ 
            "walls","White stone walls",
            "exits","There are many, which to choose..."
             });
    dest_dir = 
        ({
       "/room/church", "church",
       "/players/whisky/guild/room/tailor","down",
       "/room/post","post"
        });
}
}

