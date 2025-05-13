

/* stable */

inherit "/room/room";
#include "defs.h"

object harness;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        if (!harness) 
        {
            harness = clone_object("obj/treasure");
            call_other(harness, "set_id", "harness");
            call_other(harness, "set_short", "The nightmare's harness");
            call_other(harness, "set_alias", "harness");
            call_other(harness, "set_value",600);
            move_object(harness, this_object());
        }
        if (!present("nightmare",this_object())) 
           CM("nightmare");
         set_light(0);
         short_desc = "In the Nightmare's stable";
         long_desc = BS(
         "You are in the Nightmare's stable of Kantele's castle "+
         "The smell of sulphur lies heavy in the air. The only "+
         "way back is south onto the roof.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
         });
         dest_dir =
         ({
             PATH+"on_roof","south",
         });
      }
}

