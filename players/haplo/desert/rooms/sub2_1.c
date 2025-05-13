inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
   set_light(0);
        
     short_desc="Pyramid top floor";
        long_desc = "\
This is a square room with perfectly smooth stone walls. The strange writing \
is written all over the stone. You can still feel a draft flowing through the \
corridor you are now in. There is a curved stairway made of stone leading to \
a hole in the ceiling. You can feel a slight breeze.\n";

        dest_dir=({
          "/players/haplo/desert/rooms/sub1_4","up",
            "/players/haplo/desert/rooms/sub2_2","west"
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
