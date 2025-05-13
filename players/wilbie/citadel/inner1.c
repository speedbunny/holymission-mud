inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if(arg)return;
smell="You smell nothing but stale air.";
set_light(1);

short_desc="In a mystical room";
long_desc=
"You are in a bizarre looking room indeed.  Strange runes are scrawled all "+
"over the place, and a strange circle of dried blood covers the floor.  The "+
"feeling of evil in this place is almost overwelming.  There is a creepy "+
"silence that pervades the atmosphere.\n";

items=({
"runes","They are much too ancient to read",
"circle","It offers a way home - just kneel down",
"room","It is rather creepy",
});

dest_dir=({
CPATH+"inner2","north",
});

::reset(arg);
}
void init(){
::init();
add_action("kneel","kneel");
}

int kneel(string str){
    write("You feel reality shift.\n");
    this_player()->move_player("somewhere...",CPATH+"mainhall.c");
    return 1;
}
