 
 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
   if (filter_live(this_object()) < 1)
       CM("blue_dragon");

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
        "You are standing on a plateau near the top of the volcano. "
      + "The air is full of ash-parts so that you can hardly see anything. "
      + "There is a strange cavern in front of you maybe you can try to enter. "
      + "To the east you can see a big black rock and to the west you see "
      + "some bushes. There is a small path leading up. The plateau leads "
      + "further to the south.");
    items = ({
             "rock","A big black rock",
             "cavern","A little cavern, looking like a bar",
             "bottom","A stony bottom",
             "bushes","10 feet high bushes"
            });
    dest_dir = 
        ({
        PATH+"island21", "up",
        PATH+"island12", "south",
        PATH+"island16", "down",
        });
     CO("mushroom");
}
 init() {
   ::init();
   add_action("enter","enter");
   add_action("pass","pass");
   add_action("pass","climb");
  }

int enter(string str) 
{
 if (str=="cavern" || str=="the cavern") 
{
    write("You enter the cavern.\n");
    this_player()->move_player(
    "into a strange cavern#players/whisky/island/room/bar");
  return 1;
 }
  return 0;
}

int pass(string arg) 
{
   if (arg!="bushes" && arg!="bush") return 0;
   write("You try to pass the bushes, but on this place they seem to high.\n");
   return 1;
 }

