
/* s6e0.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In the Cove of Mordor";
        long_desc = BS(
                    SHOREDESC+" The Cove continues to the south. ");
        items = ITEMDESC + 
                ({ 
                   "cove","The big dark cove of Mordor",});
        dest_dir = ({
        _dir+"s7e1s","southeast",
        _dir+"s5e1n","northwest",
        _dir+"s6e1n","north",
        _dir+"s7e","east",
        });
        
      }
}

