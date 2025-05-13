

/* ---------------------------------------------------------------------
   filename: nshop.c last edit: 7.2.94 whisky uni-linz.ac.at 
   --------------------------------------------------------------------- */

inherit "/players/whisky/obj/std_shop";
#include "../guild.h"

int i;
int x;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the monkshop";
  long_desc = BS(
  "You have entered a small dusty room. The walls are made of red "+
  "bricks and the floor is made of spruce wooden lathes. This is the "+
  "place where Franz the monk, who is standing behind a desk, trades "+
  "with all kinds of stuff. There is a sign saying: 'type list' behind "+
  "his desk.");
  set_light(1);
   store = "/players/whisky/guild/room/nstore";

  items = ({"walls","The walls are made of red bricks",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
            "franz","He is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/whisky/guild/room/bar","west" });

    if (!present("blue scroll",query_store()))
    {
        for(x=0;x<7;x++)
        {
            move_object(clone_object("/players/whisky/obj/recall_scroll"),
            query_store());
         }
     }
    if (!present("torch",query_store()))
    {
        for(x=0;x<5;x++)
        {
            move_object(clone_object("/players/whisky/obj/torch"),
            query_store());
         }
     }
}

query_property(arg) 
{
   return arg=="no_fight";
}
