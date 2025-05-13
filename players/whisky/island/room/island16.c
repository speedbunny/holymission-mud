 
 
inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
  if (filter_live(this_object()) < 1)
      CM("green_dragon");

    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
          "You are standing on a plateau between bushes of the big volcano. "
        + "You can see the blue sea to the north and west. The air is full "
        + "of ash-parts and you can hear the rumbling noise of the volcano "
        + "To the east you see a big black rock and to the south the "
        + "plateau leads further. Maybe you can risk to jump down.");
    items = ({
          "bushes","10 feet high bushes",
          "rock","A big black rock",
          "bottom","A black stony bottom"
             });
    dest_dir = 
        ({
        PATH+"island17", "up",
        PATH+"island11", "south",
        });
}
 
init() {
  ::init();
  add_action("jump","jump");
   }

int jump() 
{
  write("************  y o u   a r e   f a l l i n g ************\n\n"+
        "************  y o u   a r e   f a l l i n g ************\n\n"+
        "************  y o u   a r e   f a l l i n g ************\n");
  this_player()->move_player("down#players/whisky/island/room/island10");
  return 1;
  }

