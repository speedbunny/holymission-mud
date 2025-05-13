
/* s7e1s.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In the Cove of Mordor";
        long_desc = BS(
                    SHOREDESC+" To the southeast you can see the southern "+
                    "end of the Cove.");
        items = ITEMDESC + 
                ({ 
                   "cove","The big dark cove of Mordor",});
        dest_dir = ({
        _dir+"s8e2s","southeast",
        _dir+"s6e0","northwest",
        _dir+"s7e0","north",
        _dir+"s8e1s","east",
        });
        
      }
}

