inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if(arg)return;

set_light(1);
smell="You smell the sea.";

short_desc="Miyamoto village";
long_desc=
"You are in the village of Miyamoto.  A steady fall of snow obscures most of "+
"your vision, but what you can see looks rather peaceful.  As most of the "+
"villagers are staying in their homes, the only sound is the steady crash "+
"of waves from the sea to your east.\n";

items=({
"sea","It's too far away right now",
"snow","It's all over the place",
"villagers","They're not here in the cold with you",
"waves","Try going to the sea",
});

dest_dir=({
FPATH+"v1","west",
FPATH+"v3","east",
});
::reset(arg); replace_program("/room/room");
}
