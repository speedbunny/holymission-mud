inherit "/room/room";     
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
smell="You smell rotten breath.";
set_light(1);

short_desc="In a dark pit";
long_desc=
"You are in a dark pit.  The only light comes from a series of holes in the "+
"ceiling, all of which are unfortunately too high for you to use for escape. "+
"There are bones scattered everywhere - some rather old, and some "+         
"disturbingly new.  All of them are broken and chewed.\n";

items=({
"holes","They would make rather nice escape routes if you could reach them",
"bones","It's hard to imagine what could have chewed them up so badly",
});

dest_dir=({
CPATH+"pit1","north",
CPATH+"pit_west1","northwest",
CPATH+"pit_east1","northeast",
CPATH+"hall1","south",
});

::reset(arg); replace_program("/room/room");
}
