inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
set_light(1);
smell="You smell the sea.";
short_desc="On the Dock";
long_desc=
items=({
"You are standing on the docks at the village of Miyamoto.  The rapidly falling "+
"snow has brought shipping to a standstill.  However, despite the snow the "+
"weather is quite pleasant.  The only noise you hear is the tranquil rumble "+
"of waves splashing against the shore./n";
"snow","It is falling rather rapidly",
"docks","They are covered in snow",
"ship","The ship is rather old, but very well kept",
});
dest_dir=({
FPATH+"d1","south",
FPATH+"d3","north",
});
::reset(arg); replace_program("/room/room");
}
