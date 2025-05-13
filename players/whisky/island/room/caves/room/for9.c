
/* for9 */

#define FRIENDS ({"orc","troll","giant"})

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 3)
     {
         CM("guard");
         CM("guard");
         CM("guard");
         CM("guard");
         CM("guard");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In a dark mixed forest, in front of a cave";
        long_desc = BS(
        "You are standing in a dark mixed forest. The branches "+
        "are slightly moving in the wind. There are shadows on the "+
        "ground which make you shiver. With any step you make you "+
        "can hear the rustling of leaves. To the east and west the "+
        "way is blocked by huge rocks and to the south you can hear "+
        "the noise of a spring. To the north you can see the entrance "+
        "to a big CAVE, which is currently blocked by rocks.");

        items = 
        ({
         "bottom","The bottom is covered leaves and humus",
         "ground","The ground is covered leaves and humus",
         "volcano","The whole vulcano is surrounding you",
         "rocks","Impossible to move them away",
         "shrubbery","Some small bushes, nutration for animals",
         "trees","You see a lot of big old trees",
         "branches","The branches are moving in the wind",
        });
        dest_dir = 
        ({
         PATH+"for6","southwest",
         PATH+"ci1","north",
         PATH+"for7","south",
         PATH+"for8","southeast",
        });
     }
}


move(str)
{
    object orc;
   if (!str) 
       str = query_verb();

   orc = present("orc",this_object());

   if (str=="north" && orc && living(orc) && !this_player()->query_invis()
       && (member_array(this_player()->query_race(),FRIENDS)==-1 ||
           this_player()->query_property("hunted_by_orcs")!=-1) )
   {
      write("An Orc bars you the way !\n");
      say(this_player()->query_name()+" is blocked by an orc !\n",         
          this_player());
      return 1;
   }
   return ::move(str);
}

