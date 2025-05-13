inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
set_light(1);
smell="You smell the sea.";
short_desc="On the Dock";
long_desc=
"You are standing on the docks of Miyamoto village.  A large ship is tied here "+
"to be loaded with her next crew.  The rapidly falling snow seems to be of "+
"great concern to the fishermen who want to go out to sea.\n";
items=({
"snow","It is falling rather rapidly",
"docks","They are covered in snow",
"ship","The ship is rather old, but very well kept",
});
dest_dir=({
FPATH+"d2","south",
FPATH+"d4","north",
});
::reset(arg); replace_program("/room/room");
}
