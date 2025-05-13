inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
smell="It smells like death";
short_desc="Depths of hell";
long_desc=
"You are on a small bridge that spans over a river of blood.  All "+    
"around you the fires of hell burn, while the damned scream in "+
"eternal agony.\n";


items=({
"damned","You can't see them through the flames",
"flames","The fires of hades",
"river","A river of blood", 
"blood","Blood of the damned",
"bridge","It spans the river of blood",
"fire","It is the fire of hades",


});

dest_dir=({
GPATH+"doom2","south",
GPATH+"doom5","north",


});

}
::reset(arg); replace_program("/room/room");
}
