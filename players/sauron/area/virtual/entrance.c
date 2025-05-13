inherit "/players/sauron/inherit/borderRoom";

#include "/players/sauron/include/virtual.h"

void reset(int iArg ) {
    if(!iArg) {
        set_light(1);
        short_desc="Virtual area entrance.";
        long_desc="\
This room is the entrance to the test virtual area managed by the \
testMaster.c in this directory. If you have not entered this room \
from my workroom, and the virtual area is not initialised, you will \
get an error. The answer is to update everything in this directory, \
and enter from my workroom as you are supposed to! If you can't do \
that through lack of entrance privelidges, maybe you shouldn't be \
here...\n";
        addExit("up","/players/sauron/workroom");
        addExit("down","/players/sauron/area/virtual/testMaster,0,0,0");
    }
    ::reset(iArg);
}
