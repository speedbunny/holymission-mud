inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You have come to a dead end of sorts.  Billowing hellfire surrounds "+
"you except for a narrow path to the west.  Sinister runes are drawn "+
"here on the ground, with what looks like blood.\n";



items=({
"runes","They are arcane runes",
"blood","It is dried onto the ground",
"flames","They are the fires of hell",
"path","You can go that way",
"fire","It is the fire of hades",


});

dest_dir=({
GPATH+"doom6","west",


});

clone_list=({
 1,3,"narguhl","/players/wilbie/graveyard/monsters/narguhl",0,
});
}
::reset(arg); replace_program("/room/room");
}
