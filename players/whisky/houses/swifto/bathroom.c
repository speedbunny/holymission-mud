
/* entrance */

inherit "/room/room";
#include "defs.h"

object ch;
object robe1;
object robe2;
int i;

void reset(int flag)
{
  if (!ch)
  {
    for (i=0; i < 2; i++)
    {
      ch = clone_object("/obj/alco_drink");
      ch->set_name("champagne");
      ch->set_alias("bottle");
      ch->set_drinking_mess(" drinks some champagne.\n");
      ch->set_long("A bottle of best, french champagne.\n");
      ch->set_strength(1);
      ch->set_value(1);
      move_object(ch,this_object());
    }
  }
  if (!robe1)
  {
     robe1 = clone_object("/obj/armour");
     robe1->set_name("pink robe");
     robe1->set_alias("robe");
     robe1->set_type("cloak");
     robe1->set_short("A soft, pink, satin robe");
     robe1->set_long("A soft pink bathrobe.\n");
     robe1->set_value(10);
     move_object(robe1,this_object());
   }
  if (!robe2)
  {
     robe2 = clone_object("/obj/armour");
     robe2->set_name("blue robe");
     robe2->set_alias("robe");
     robe2->set_type("cloak");
     robe2->set_short("A soft, blue, satin robe");
     robe2->set_long("A soft blue bathrobe.\n");
     robe2->set_value(10);
     move_object(robe2,this_object());
   }
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In the bathroom of Swifto's house";
         long_desc = BS(
         "You have entered the bathroom of Swifto's house. "+
         "It's a medium sized room and most of it is taken "+
         "up by a rather large tub, apparently built for two "+
         "The tub is full of warm water and there is a small "+
         "fireplace and a sofa next to the western wall."); 

        items =
        ({
         "walls","The walls are painted in white",
         "floor","The floor is hardwood",
         "ceiling","The ceiling is made of spruce wooden lathes",
         "fileplace","A small fireplace",
         "tub","It is a big bath tub full of warm bubbly water",
         "sofa","A soft white sofa", 
        });

         dest_dir =
         ({
           PATH+"bedroom","south",
           PATH+"tube","tub",
           PATH+"toilet","north",
         }); 
     }
  }




    
