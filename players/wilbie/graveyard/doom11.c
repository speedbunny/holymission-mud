inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"Here in this dark, barren room lies the den of Sheankala.  Goddess "+
"of Darkness and Emptyness, she seeks only the ruin of all that is "+
"pure and good!\n";



items=({
"fire","It is the fire of hades",
"room","It is rather plain",


});

dest_dir=({
GPATH+"doom10","south",


});

clone_list=({
 1,1,"goddess","/players/wilbie/graveyard/monsters/goddess",0,
-1,1,"blade","/players/wilbie/graveyard/weapons/goddess_sword",0,
});
}
::reset(arg); replace_program("/room/room");
}
