
/* s3e1n.c */

inherit "/room/room";

#include "/players/whisky/mordor/sys/shore.h"

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In the Cove of Mordor";
        long_desc = BS(
                    SHOREDESC+" The Cove continues to the east and north. ");
        items = ITEMDESC + 
                ({ 
                   "cove","The big dark cove of Mordor",});
        dest_dir = ({
        _dir+"s2e","southwest",
        _dir+"s4e2n","northeast",
        _dir+"s2e1n","west",
        _dir+"s3e2n","north",
        });
        
      }
}

