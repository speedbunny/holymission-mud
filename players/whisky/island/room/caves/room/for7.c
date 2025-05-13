
/* for7 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
         CM("hunter");
         CM("hunter");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the Heart of the Forest";
        long_desc = BS(
        "You are standing in the 'Heart of the forest'. The branches "+
        "are slighly moving in the wind. There are shadows on the "+
        "ground which make you shiver. With any step you make you "+
        "can hear the rustling of leaves. In the distance you can "+
        "hear the rumbling of the volcano. Next to your feet is a "+
        "'small spring' with some water coming out.");

        items = 
        ({
         "bottom","The bottom is covered leaves and humus",
         "ground","The ground is covered leaves and humus",
         "volcano","The whole vulcano is surrounding you",
         "shrubbery","Some small bushes, nutration for animals",
         "trees","You see a lot of big old trees",
         "branches","The branches are moving in the wind",
         "spring","Well, the water looks like you can 'drink' from it",
        });
        dest_dir = 
        ({
         PATH+"for9","north",
         PATH+"for6","west",
         PATH+"for8","east",
         PATH+"for3","south",
        });
     }
}

void init()
{
     ::init();
     add_action("do_drink","drink");
}


int do_drink(string str)
{
    if (!str)
        return 0;
    else if (strstr(str,"spring")!=-1 || strstr(str,"water")!=-1)
    {
        write("Ahh, the water refreshes you !\n");
        say(this_player()->query_name()+" drinks from the spring.\n");
        return 1;
    }
    return 0;
}

