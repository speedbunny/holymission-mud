

inherit "room/room";
#include "../island.h"

void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
      CM("green_dragon");

  if (arg) return;
    set_light(1);
    short_desc = "On an island";
    long_desc =  BS(
        "You are standing on a plateau near the top of the volcano. "+
        "The air is here very hot and the gas coming from the volcano "+
        "nearly causes you to fall into unconsciousness. "+
        "To the north and east you see the blue sea. Far in the distance "+
        "you can see a 'Big Volcano Peak' in the middle of the ocean. "+
        "Strange, but it looks nearly like the mountain where you are. "+
        "Only this volcano peak doesn't seem active. Maybe in earlier "+
        "times part of island sunk in the ocean.");
       
    items = ({
          "volcano","A big black volcano",
          "beach","A long sandy beach",
          "rock","A big black rock",
          "bottom","A fine sandy bottom",
          "peak","It looks nearly as big as the mountain where you are at",
            });
    dest_dir = 
        ({
        PATH+"island22", "west",
        PATH+"island19", "south",
        });
}

