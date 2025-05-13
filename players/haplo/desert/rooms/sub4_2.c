inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
   set_light(0);
        
     short_desc="Pyramid top floor";
        long_desc = "\
This room seems darker than the others. The writing on the wall is smudged as \
if someone has rubbed up against it. You feel a great amount of terror \
emminating from the north. There are scraps of what looks like rotting linen \
scattered across the floor.\n";

        dest_dir=({
    "/players/haplo/desert/rooms/sub4_3","north",
    "/players/haplo/desert/rooms/sub4_1","south"
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
