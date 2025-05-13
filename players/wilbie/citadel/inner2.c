inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if(arg)return;

smell="You smell only stale air.";
set_light(1);

short_desc="In a grisly hall";
long_desc=
"You have entered a hallway of roughly hewn rock.  The walls are covered "+
"with the grisly remains of what might have been a female elf at some time. "+
"Her twisted body has been ripped apart too much to be sure however.\n";

items=({
"body","It makes you feel rather sick to look",
"hallway","You wonder what could have torn it apart like that",
});

dest_dir=({
CPATH+"inner1","south",
CPATH+"inner3","north",
});

::reset(arg);
}

void init(){
::init();
add_action("north","north");
add_action("north","n");
}

int north(){
write("You hear a low growl...\n");
this_player()->move_player("leaves north.",CPATH+"inner3.c");
return 1;
}
