
/* tube */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
        short_desc = "In a big wooden bath-tub";
         long_desc = BS(
         "You are inside a big wooden bathtub. It's full of "+
         "pleasant warm water. The water is parfumed and smells "+
         "like red roses."); 
        
        items =
        ({
         "water","The warm water smells like red roses",
         "tub","You are inside of the big tub",
        });

         dest_dir =
         ({
           PATH+"bathroom","out",
         }); 
     }
   }

void init()
{
    ::init();
    this_player()->set_smell(this_player()->query_pronoun()+
                   " smells wonderful like red roses !"); 
}

