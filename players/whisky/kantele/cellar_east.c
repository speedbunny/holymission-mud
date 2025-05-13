
/* cellar east */

inherit "/room/room";
#include "defs.h"

int moved;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        moved = 0;
        short_desc = "In a large dark hall";
        long_desc = BS(
        "You are in a large dark hall, you can enter the stairway "+
        "to the west. To the north are some barrels and to the west "+
        "the stairway leads down into another dark room.");
     
        items = 
        ({
            "hall","A dark hall, with maybe a secret",
            "stairway","There is a wooden stairway to the west",
            "barrels","Some barrels leaning against the wall, "+
                      "probably moveable",
        });
     }
     if (moved)
     {
         dest_dir = dest_dir + 
                    ({PATH+"cellar_passage","north"});
     }
     else if (sizeof(dest_dir) < 2)
        dest_dir = ({PATH+"stairway_down","west"});
}


void init()
{
    ::init();
    add_action("my_move","move"); 
}

int my_move(string arg) 
{
   if (arg == "barrel" || arg == "barrels") 
   {
      if (moved)
      {
          write("You move the barrels to barrier the secret passage.\n");
          moved = 0;
          reset(1);
          init();
      }
      else 
      {
        write("You move the barrels to reveal a secret passage.\n");
        moved=1;
        reset(1);
        init();
       }
       say(this_player()->query_name()+" moves the barrels.\n",this_player());
       return 1;
   }
   return 0;
}



