inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
smell="It smells like death";
short_desc="Depths of hell";
long_desc=
"The rotten stench of death and burning flesh fills the air.  To the "+ 
"east grows some grotesque sort of tree, bearing odd looking fruit. "+
"To the north there is a small bridge over a river of blood.\n";



items=({
"river","It is blood",
"blood","It is the blood of the damned",
"bridge","If goes over the river of blood",
"tree","You can't see it very well from here",
"fruit","You're too far away to get a good look",
"fire","It is the fire of hades",


});

dest_dir=({
GPATH+"doom3","west",
GPATH+"doom4","north",
 "/players/wilbie/barriers/doom1","south",

});

}
/*  Not using GPATH for south so that monsters cloned here do not wander
    upstairs...
*/
::reset(arg); replace_program("/room/room");
}
