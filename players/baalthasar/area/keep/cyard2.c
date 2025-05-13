inherit "room/room";
#include "../path.h"

reset(arg) {
if (arg) return;
set_light(1);
property = ({"no_teleport"});
short_desc = "Southwest courtyard";
long_desc =  
"      More merriment and people flood these corners of the \n"
+"great castle's courtyard. \n"
+"      You see to the west a large building which appears to \n"
+"house many of the castles soldiers.  The door is slightly ajar \n"
+"and voices can be heard within.  From the northwest come the \n"
+"sounds of combat and yelling.  A path leads northwest. \n\n";
dest_dir =
({
PATH + "/sbarak", "door",
PATH + "/train1", "northwest",
PATH + "/cyard4", "north",
PATH + "/cyard5", "northeast",
PATH + "/cyard1", "east" 
});
}
