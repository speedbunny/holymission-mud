inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You are on a small path in front of an ancient shrine.  The fires "+
"of hades are less furious here, as if in deference to the evil "+
"power within.\n";



items=({
"shrine","A shrine to Sheankala, Goddess of the Dark",
"fires","They are lesser here",
"fire","It is the fire of hades",


});

dest_dir=({
GPATH+"doom6","south",
GPATH+"doom9","north",


});

}
::reset(arg); replace_program("/room/room");
}
