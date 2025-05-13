inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
   set_light(0);
        
     short_desc="Pyramid top floor";
        long_desc = "\
You are in the magnificent treasury of the great pharoah. There are many \
treasures around here. The room is decorated with beautiful tapestries and \
the shelves are filled with many treasures stacked high above your head. \
The room is lit by an eerie glow from the ceiling which you can't see very \
clearly due to it's height.\n";

        dest_dir=({
     "/players/haplo/desert/rooms/sub4_3","south"
        });
           
    property=({"no_teleport"});
        items = ({
"tapestries","They are magnificently woven designs that honor the Reign of Pharoah",
"shelves","They are to high for you to reach unfortuantely",
"treasure","More than you can spend in your lifetime"
        });
           
        property = ({
        });
    }
    ::reset(arg);
    replace_program("/room/room");
}
