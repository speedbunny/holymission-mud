 

inherit "room/room";
#include "../island.h"
 
void reset(int arg) 
{
  if (filter_live(this_object()) < 2)
  {
     CM("monkey");
     CM("monkey");
  }
   if (arg) return;
   set_light(1);
   short_desc = "On an island";
   long_desc = BS(
          "You are standing in the middle of a row of palm-trees. "
        + "The bottom is full of white sand and you can hear shrieks of "
        + "the famous island monkeys playing around and gathering coconuts. "
        + "To the north you see a big rock and to the east some more " 
       + "palm-trees and you can hear a strange drum-roll from the east.");
    items = ({
              "sand","A beautiful white sand",
            });
            
    dest_dir = 
        ({
        PATH+"island9", "east",
        PATH+"island7", "west",
        PATH+"island4", "south",
        });
     CO("tree");
}
