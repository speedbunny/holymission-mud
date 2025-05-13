

/* main_shop */

inherit "/obj/std_shop";
#include "/players/whisky/genesis/sys/break_string.h"

#define  BS(x) break_string(x+"\n",60)

void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In Sleepy's outfitter";
  long_desc = BS(
  "You have entered a small dusty room. The walls are made of red "+
  "bricks and the floor is made of spruce wooden lathes. This is the "+
  "place where Sleepy the trader, who is standing behind a desk, trades "+
  "with all kinds of stuff. There is a sign saying: 'type list' behind "+
  "his desk.");
   set_light(1);
   store = "/room/main_store";
   keeper = "Sleepy";

  items = ({"walls","The walls are made of red bricks",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
            "franz","He is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/room/vill_road2","south" });

    move_object(clone_object("/obj/torch"),query_store());
    move_object(clone_object("/players/cashimor/objects/match"),query_store());

}

query_property(arg) 
{
   return arg=="no_fight";
}
