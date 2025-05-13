
/* ci46 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
         CM("troll");
         CM("troll");
         CM("shaman");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "Next to a stone stairway";
        long_desc = BS(
        "You are standing in front of a small stone stairway. "+
        "When you look up you see some light coming from this "+
        "place and you can hear someone growling. The stairway "+
        "ends in a huge doorway. The only secret way seems to "+
        "go back to the south.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood", 
         "stairway","A small stone stairway leading up",
         "doorway","A big stone doorway",
         "moss","Green wet moss",
        });
      }
     dest_dir = 
     ({
       PATH+"ci47","up",
       PATH+"ci45","south",
     });
}

int move(string str)
{
    object troll;

    if (!str)
         str = query_verb();

    troll = present("troll",this_object());

    if (str=="up" && troll && living(troll))
    {
        write("You are blocked by a cave troll guard !\n");
        say(this_player()->query_name()+" is blocked by a cave troll "+
            "guard.\n",this_player());
        return 1;
    }
    return ::move(str);
}

