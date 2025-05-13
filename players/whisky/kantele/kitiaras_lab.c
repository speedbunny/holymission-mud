
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
        dest_dir = ({
          PATH+"kitiaras_innerhall","west",
          PATH+"kitiaras_magesroom","north",
        });

         short_desc = "In a small lab";
         long_desc = BS(
         "You are in a small well lit laboratory, lots of strange things " +
         "can bee seen in this room, you feel lost in the affair of the " +
         "immortals.");
          items = ({
          "bottom","The bottom is made of fouly wood",
          "ceiling","The ceiling is made of red bricks",
          "walls","The walls are made of red bricks",
          });
      }
}

