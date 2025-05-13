
/* s9e2s.c */

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
                    "Far to the south you can see the outline of a "+
                    "big island.");
        items = ITEMDESC + 
                ({ 
                   "cove","The big dark cove of Mordor",
                   "island","Far to the south you can see the outline\n"+
                            "of a big island",
                   "rock","A big black rock. Too steep to climb",});
        dest_dir = ({
        _dir+"s10e2s","east",
        _dir+"s8e2s","west",
        _dir+"s9e1s","north",
        });
        
      }
}

