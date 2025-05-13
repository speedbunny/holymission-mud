inherit "/room/room";
#include "/players/brainsprain/bis/bisdef.h"

void reset(int arg)
{
  ::reset(arg);
  if (arg!=0) return;
  set_light(1);
  short_desc = "In the Towpath Store";
  long_desc = 
    "This is the Storeroom of the Towpath Store.  Only Relmux or one of his "+
    "trusted apprentices should be down here.   Relmux keeps all the items he "+
    "has to sell in this room.  He does not seem to be one for organization "+
    "as all the items are piles on the ground.\n";
  clone_list = ({
    1, 1, "Scroll1", bi+"/scroll1.c", 0,
    5, 2, "pack", bi+"/backpack.c", 0,
    2, 1, "Potion0", "/players/whisky/obj/invis_potion.c", 0,
    2, 1, "Potion0", "/players/whisky/obj/invis_potion.c", 0,
    3, 1, "Potion1", bi+"/potion1.c", 0,
    1, 1, "pois", bi+"/pois.c", 0,
    4, 8, "Arrow", bi+"/arrow.c", 0,
  });
  dest_dir = ({
    br+"/mage.c","up",
  });
  ::reset(arg); 
  replace_program("room/room");
}

