inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
set_light(1);
smell="You smell the sea.";
short_desc="On the Docks";
long_desc=
"You are standing on the snow covered docks of Fuzhao village.  The crashing "+
"waves of the sea and the shrill sounds of freezing wind fill your ears. "+
"Despite the weather conditions, you feel a sense of peace in this place. "+
"To the north there is a ship tied to the docks.\n";
items=({
"ship","It looks like a large fishing vessel",
"docks","They are covered in snow",
"snow","It is still falling",
"wind","You can see the snow blowing, but not the wind itself",
"sea","It looks really rough",
"weather","It's getting bad",
});
dest_dir=({
FPATH+"d5","north",
FPATH+"d3","south",
});
::reset(arg); replace_program("/room/room");
}
