inherit "room/shop";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Towpath General Store";
    long_desc =
"This is the Towpath General Store.  A counter starts near the door "+
"and goes around the length of the room.  To the south is a man who "+
"is waiting to take your order.  The commands are list, sell, buy "+
"and sell all.\n";
dest_dir = ({
    br+"/tr-7.c","north",
  });
store_exit = "south";
store_room = clone_object(br+"/store");
  }
