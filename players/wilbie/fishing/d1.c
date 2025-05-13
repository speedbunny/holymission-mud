inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
set_light(1);
smell="You smell the sea.";
short_desc="On the Dock";
long_desc=
"You are at the southern end of the docks of Miyamoto village.  The weather "+
"quite beautiful, despite the rapidly falling snow.  Only the constant "+
"rumble of waves crashing serves as a distraction./n";
-
items=({
"snow","It is falling rather rapidly",
"docks","They are covered in snow",
"ship","The ship is rather old, but very well kept",
});
dest_dir=({
FPATH+"d2","north",
});
::reset(arg); replace_program("/room/room");
}
