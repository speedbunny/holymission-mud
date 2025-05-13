inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
smell="It smells like death";
short_desc="Depths of hell";
long_desc=
"You surely stand before the entrance to hades itself.  Fire and "+
"brimstone burn all around, and the screams of the damned fill your "+
"ears.  The ground is crushed bone, and to the north flows a river "+
"of what could only be blood.\n";



items=({
"bones","They have been crushed into powder",
"river","It is a river of blood",
"blood","It is the blood of the damned",
"hades","It is a horrible place indeed",
"fire","It is the fire of hades",


});

dest_dir=({
GPATH+"hell5","up",
GPATH+"doom2","north",


});

}
::reset(arg); replace_program("/room/room");
}
