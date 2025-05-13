inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(!arg)  {
set_light(1);
short_desc="In the painting";
long_desc=
"You are standing before an open grave.  The area is surrounded by "+
"solid walls of blackness.  Only a painting of a hallway hanging in mid-air "+
"offers any form of exit.\n";

items=({
"grave","It is an uncovered grave",
"portal","It is the size of a painting",
});


}
::reset(arg);
}
void init() {
::init();
add_action("enter","enter");
add_action("enter","search");
add_action("touch","touch");
}            

int enter(string str) {
if(str=="grave") {
write("You are pulled into the grave!!\n");
this_player()->move_player("into the grave",GPATH+"grave.c");
return 1;
}
notify_fail("What do you mean?\n");
return 0;
}


int touch(string str) {
if(str=="painting") {
write("You are pulled through!!\n");
this_player()->move_player("through the painting",GPATH+"up4");
return 1;
}
notify_fail("Touch what??\n");
return 0;
}
