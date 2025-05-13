 
 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{

   if (filter_live(this_object()) < 1)
      CM("snake");

   if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
          "You are standing at a plateau of the big volcano. "
        + "The air is full of ash particles and you can hear the "
        + "loud noise of the rumbling volcano. If you look down "
        + "you can sea the blue sea. To the east a small path "
        + "leads up the mountain.");
    items = ({
              "volcano","A big firethrowing volcano",
              "sea","The blue sea",
              "path","A small path leading up"
            });
    dest_dir = 
        ({
        PATH+"island12", "up",
        PATH+"island16", "north",
        PATH+"island5", "south",
        });
}
  init() {
   ::init();
   add_action("jump","jump");
   }

int jump() 
{
   this_player()->move_player(
   "down the rock#players/whisky/island/room/island10");
   return 1;
}
