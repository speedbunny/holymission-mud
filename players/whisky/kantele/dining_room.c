
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
    if (flag == 0)
    {
      dest_dir = ({
          PATH+"inner_hall","east",
          PATH+"kitchen","south",
      });

      short_desc =  "In the dining room";
      long_desc = BS(
         "A beautiful dining room. This room is decorated with dark cedar "+
         "panels and you can smell cooking to the south.");
      items = ({
      "bottom","The bottom is made of fouly oaken lathes",
      "ground","The bottom is made of fouly oaken lathes",
      "ceiling","The ceiling is covered with gray dust",
      "walls","The walls are made of grey bricks"
      });
  }
}


