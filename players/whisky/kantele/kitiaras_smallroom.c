
inherit "/room/room";
#include "defs.h"

int res;

void reset(int flag)
{
     if (flag == 0)
     {
       dest_dir = 
       ({
          PATH+"kitiaras_livingroom","west",
       });
 
        short_desc = "A small dirty room";
        long_desc = BS(
        "This is a small dirty room, with lots of strange rubble.");
        items =
        ({
         "bootom","The bottom is made of fouly wood",
         "ceiling","The ceiling is made of red bricks",
         "walls","The walls are made of red bricks",
         "rubble","Nothing special just rubble",
        });
     }
     res = 0;
}

void init()
{
   add_action("do_search","search");
   ::init();
}

int do_search(string arg)
{
    if (arg!="rubble")
        return 0;
    write("You search the rubble");
    say(this_player()->query_name()+" searches the rubble.\n");
    if (res)
       write(", but find nothing.\n");
    else
    {
       write(" and found a small stick.\n");
       CO("stick");
       res = 1;
    }
    return 1;
}


