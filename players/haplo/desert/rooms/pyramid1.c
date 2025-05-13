inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
   set_light(0);
        
     short_desc="Pyramid top floor";
        long_desc = "\
You are in a room with three walls that come to a point above your head. The \
stone walls are smooth with no visible cracks. Painted on them are many \
various pictures and marks that look like writing of ancient origin. The \
dust is thick in here and you can feel a faint draft coming up from below. \
There are curved stairs descending to a room below.\n";

        dest_dir=({
      "/players/haplo/desert/rooms/sub1_1","down"
        });
           
    property=({"no_teleport"});
        items = ({
"dust","There is a thick carpet of dust ont he floor",
"writing","It look slike the pictorial writing of ancient Eygpt",
"pictures","They are pictures of people doing various things",
"door","There is no trace of the door that leads in here from outside",
        });
           
        property = ({
        });
    }
    ::reset(arg);
    replace_program("/room/room");
}
