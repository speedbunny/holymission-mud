 
inherit "room/room";
#include "../hole.h"
 
void reset(int arg) 
{
   if (filter_live(this_object()) < 4)
   {
     CM("baby_drake");
     CM("baby_drake");
     CM("baby_drake");
     CM("baby_drake");
   }
   if (arg) return;
   set_light(0);
   short_desc = "In a dark hole";
   no_castle_flag = 0;
   long_desc = BS(
        "You have now entered the sixth floor of the black hole. "
      + "It's so hot here that you feel you could die. "
      + "You suddenly get the strange feeling that there must be "
      + "a great evil nearby. "
      + "A tiny corridor leads further to the west, up and down.");
    dest_dir = 
        ({
    PATH+"h17","west",
    PATH+"h16","up",
    PATH+"h19","down"
        });
}
 
