 

inherit "room/room";
#include "../island.h"


void reset(int arg) 
{
    if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc = BS(
          "You are standing on a plateau near the top of the volcano. "
        + "The air is full of ash that you can hardly see anything. "
        + "To the north you can see a big black rock and to the south. "
        + "if you look down you'll sea the blue see and the top of the "
        + "palm trees. You also hear a strange growling getting louder.");
    items = ({
            "rock","A big black rock",
            "sea","The clear blue sea",
            "trees","100 foot high palm trees",
            "palm trees","100 foot high palm trees"
            });
    dest_dir = 
        ({
        PATH+"island12", "west",
        PATH+"island14", "up",
        });
}
