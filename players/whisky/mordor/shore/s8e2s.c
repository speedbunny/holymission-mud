
/* s8e2s.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "Next to a big Rock";
        long_desc = BS(
                    SHOREDESC+" Next to you is a big black Rock. "+
                    "To the north and west you can see the big Cove "+
                    "of Mordor.");
        items = ITEMDESC + 
                ({ 
                   "cove","The big dark cove of Mordor",
                   "rock","A big black rock. Too steep to climb",});
        dest_dir = ({
        _dir+"s9e2s","east",
        _dir+"s7e1s","northwest",
        _dir+"s8e1s","north",
        });
        
      }
}

