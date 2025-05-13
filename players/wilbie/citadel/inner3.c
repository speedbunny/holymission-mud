inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(arg)return;
set_light(1);
smell="You smell death.";
short_desc="A dark pit";
long_desc=
"You stand before a darkened pit.  Fresh blood is smeared along the sides, "+
"and wicked looking claw marks run deep in the stone floor.  Something "+
"awfully big must have been here.\n";

items=({
"pit","A dark pit",
"blood","Fresh blood",
"claw marks","They are rather deep",
"marks","The claw marks of some powerful creature",
});

dest_dir=({
CPATH+"inner2","south",
});

::reset(arg);
}                 

void init(){
   ::init();
         add_action("down","down");
         add_action("down","d");
           }

int down(){
write("You fall!");
this_player()->move_player("rather quickly down...",CPATH+"pit1.c");
    return 1;
          }
#include "/players/wilbie/def.h"
