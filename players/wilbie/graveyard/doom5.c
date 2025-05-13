inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You are just north of the river of blood.  The stench of death is "+
"overpowered here by the smell of brimstone.  Here the hideous "+
"minions of hades have set up a checkpoint.\n";

items=({
"fire","It is the fire of hades",
"checkpoint","It is a simple checkpoint",


});

dest_dir=({

GPATH+"doom4","south",
GPATH+"doom6","east",

});
clone_list=({
 1,3,"merillith","/players/wilbie/graveyard/monsters/merillith",0,
});

}
::reset(arg); replace_program("/room/room");
}
