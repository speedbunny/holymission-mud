inherit "/players/sauron/inherit/virtualRoom";

#include "/players/sauron/include/include.h"

void reset(int iArg) {
    if(!iArg) {
        set_light(1);
        short_desc="A virtual room.";
        long_desc="There isn't much here right now... sorry. :)\n";
    }
    ::reset(iArg);
}
