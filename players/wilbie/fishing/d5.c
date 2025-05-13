inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
set_light(1);
smell="You smell the sea";
short_desc="End of the docks";
long_desc=
"You are at the northernmost end of the docks.  A large rocky cliff rises "+
"up from the sea here, right up against the dock.  Waves splash against the "+
"rough rocks and streams of whitewater trickle down in waterworn crevices. "+
"The waves crash mightily here.\n";   
items=({
"waves","They are rather large here",
"rocks","It has a lot of holes in it from erosion",
"rock","It has a lot of holes eroded into it",
"streams","They run down the rock",
"whitewater","It is from the crashing waves",
"crevices","They are well worn from ages of waves",
"holes","They are well worn from the ages of crashing waves",
"docks","They are very old, but well taken care of",
});
dest_dir=({
FPATH+"d4","south",
});
::reset(arg); replace_program("/room/room");
}

void_init(){
::init();
add_action("climb","climb");
}

int climb(){
write("You climb the ragged rocks");
this_player()->move_player("up the rocks",FPATH+"r1");
}
