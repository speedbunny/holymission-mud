inherit "room/room";
#include "../path.h"

reset(arg) {
if (arg) return;
set_light(1);
property = ({"no_teleport"});
short_desc = "Southeast courtyard";
long_desc =  
"      More merriment and people flood these corners of the \n"
+"great castle's courtyard. \n";
  dest_dir = ({
PATH + "/cyard1", "west",
PATH + "/cyard5", "northwest",
PATH + "/cyard6", "north"
});
}
