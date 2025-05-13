
/* s5e1n.c */

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
        _dir+"s6e","southeast",
        _dir+"s4e2n","northwest",
        _dir+"s5e2n","north",
        _dir+"s6e1n","east",
        });
        
      }
}

