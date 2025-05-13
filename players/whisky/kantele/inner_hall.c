

/*  inner hall */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (!present("henry",this_object()))
         CM("henry");
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Inside the inner hall";
         long_desc = BS(
         "You are in the inner hall of Kantele's castle. "+
         "The walls are lined with shields. "+
         "It looks like the shields are loot from some sort of campaign.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "shields","The walls are lined with shields",
         });
         dest_dir =
         ({
             PATH+"living_room","east",
             PATH+"stairway","south",
             PATH+"dining_room","west",
             PATH+"hall","north",
         });
      }
}

int move(string str)
{
    object james;

    james = present("henry",this_object());

    if (!str)
        str = query_verb();

    if (str == "south" && james && living(james) )
    {
       command("say I don't let you pass !",james);
       return 1;
    }
    return ::move(str);
}

