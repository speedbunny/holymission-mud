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
CPATH+"pit_east1","east",
CPATH+"pit_west1","west",
CPATH+"pit_east2","south",
CPATH+"pit_west2","north",
CPATH+"pit_west3","northwest",
CPATH+"pit_east4","southeast",
});

::reset(arg); replace_program("/room/room");
}
