inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;

set_light(1);
smell="You smell the sea.";

short_desc="In Miyamoto village";
long_desc=
"You are in the western end of Miyamoto village.  The village sits in the middle of "+
"a small pine forest.  The village looks peaceful, but somehow you can tell "+
"that it has seen more than it's share of bloodshed.  To your north is a "+
"rather quaint looking inn, while to your south is the home of the local "+
"ruler.  The village continues to the east and west.\n";

items=({
"village","The rather peaceful village of Miyamoto",
"inn","It looks rather inviting",
"home","It is a regal looking place",
"forest","There are pine trees all around",
});

dest_dir=({
FPATH+"v2","east",
FPATH+"inn","north",
FPATH+"hall1","south",
FPATH+"p4","west",
});
::reset(arg); replace_program("/room/room");
}
