

/* snake_room */

inherit "/room/room";
#include "defs.h"

int rope;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(0);
         short_desc = "In a room with a pit";
         long_desc = BS(
         "You have entered a small room with a big pit, "+
         "the only exit seems to be west, "+
          "and you can see a large pillar standing beside the pit.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "pit","You look down in the pit, it seems slipery,\n"+
                  "and imposible to climb down",
            "pillar","A big pillar to fix a rope",
         });
         dest_dir =
         ({
             PATH+"kitiaras_crossing","west",
         });
      }
}

    
    
void init()
{
    ::init();
    add_action("down","down"); 
    add_action("down","d"); 
    add_action("down","jump"); 
}

int id(string arg)
{
    return arg == "pillar";
}   

int down() 
{
     write("You don't have the selfdiscipline to jump in that shaft !\n");
     return 1;
}
 /*
    if (!rope) {
        write("You would fall down the pit and possible hurt yourself.\n");
        return 1;
    }
    this_player()->move_player("down#players/kantele/snake_pit");
    return 1;
}

  */
int tie(string str)
{
    if (str != "pillar")
        return 0;
    rope = 1;
    return 1;
}

int untie(string str) 
{
    rope = 0;
    return 0;
}

int query_rope() 
{
    return rope;
}

int jump_down(string arg) 
{
    if (!arg || arg == "down")  
    {
       write("You throw yourself into the pit !\n");
       write("You hit the dirt hard......\n");
       this_player()->move_player("jump_down#players/kantele/snake_pit");
       return 1;
    }
   return 0;
}

