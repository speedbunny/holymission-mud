inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
        set_light(1);
        
        short_desc = "Island";
        long_desc = "\
You stand before a door leading into what looks like a small pyramid. The \
wind is whipping around you stirring up the desert sand. The sun continues \
to beat mercilessly down on you.\n";

        dest_dir=({
            ISLPATH+"forest2", "north",
        });
           
        items = ({
            "puddles", "The puddles are slimy and stagnant you really \
don't want to touch it",
            "path", "The path leads through the forest. You wonder who \
made it",
        });
           
        property = ({
        });
    }
    ::reset(arg);
    replace_program("/room/room");
}
