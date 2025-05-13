
/* s2e.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "On a dark Shore";
        long_desc = BS(
                    SHOREDESC+" far to the south you can see the outline "+
                    "of a big island. To the east you see the big cove "+
                    "of Mordor.");
        items = ITEMDESC + 
                ({ "island","Far to the south you can see land",
                   "cove","The big dark cove of Mordor",});
        dest_dir = ({
        _dir+"s3e1n","northeast",
        _dir+"s1e","west",
        _dir+"s2e1n","north",
        });
        
      }
}

