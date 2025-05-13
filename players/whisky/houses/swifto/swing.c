
/* swing */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In a big swing";
         long_desc = BS(
         "You are sitting inside a big, red swing. From this place "+
         "You have a great look at the beautiful lake. "+
         "The swing looks as you can 'swing' up and down "+
         "enjoying this picturesque landscape.");
        
        items =
        ({
         "swing","A beautiful, red swing",
         "lake","You see the beautiful blue lake",
         "landscape",
         "You see the beautiful blue lake, the forest, the beach\n "+
         "and some seagulls flying over the water catching fish",
        });

         dest_dir =
         ({
           PATH+"deck","out",
         }); 
     }
}

void init()
{
   ::init();
   add_action("do_swing","swing");
}

int do_swing()
{
   tell_room(this_object(),
   "The big swing moves softly up and down.\n");
   return 1;
}

