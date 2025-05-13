inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
   set_light(0);
        
     short_desc="Pyramid top floor";
        long_desc = "\
This is a square room with perfectly smooth stone walls. The strange writing \
is written all over the stone. You can still feel a draft flowing through the \
corridor your are now in. There is a curved, stone staircase descending to a \
lower level.\n";

        dest_dir=({
    "/players/haplo/desert/rooms/sub1_3","north",
    "/players/haplo/desert/rooms/sub2_1","down"
        });
           
    property=({"no_teleport"});
        items = ({
"dust","There is a thick carpet of dust ont he floor",
"writing","It look slike the pictorial writing of ancient Eygpt",
"pictures","They are pictures of people doing various things",
        });
           
        property = ({
        });
    }
    ::reset(arg);
    replace_program("/room/room");
}
