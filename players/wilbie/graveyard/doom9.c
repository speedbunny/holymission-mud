inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You are just inside the evil shrine of Sheankala.  Up ahead to the "+
"north, the goddess herself resides!\n";



items=({
"shrine","An evil shrine to the dark goddess",
"goddess","You cannot see her yet",
"fire","It is the fire of hades",


});

dest_dir=({
GPATH+"doom10","north",
GPATH+"doom8","south",


});

}
::reset(arg); replace_program("/room/room");
}
