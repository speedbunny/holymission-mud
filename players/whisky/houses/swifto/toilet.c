
/* toilet */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In the toilet of Swifto's house";
         long_desc = BS(
         "You have entered a very small room in Swifto's house. "+
         "In the middle of the room is a big, clean loo. "+
         "There is a small paper dispenser fixed to the western "+
         "wall and a washing basin is fixed to the eastern wall.");
        
         
        items =
        ({
         "walls","The walls are painted in white",
         "western wall",
         "There is a big paper dispenser fixed to the western wall",
         "floor","The floor is hardwood",
         "ceiling","The ceiling is painted in white",
         "loo","It' a clean place where people do their business",
         "dispenser","You can tear soft white paper from it",
         "bassin","This is the place where you can wash your hands",
        });

         dest_dir =
         ({
           PATH+"bathroom","south",
         }); 
     }
   }

void init()
{
    ::init();
    add_action("do_tear","tear");
    add_action("do_sit","sit");
    add_action("do_wash","wash");
}

int do_wash(string arg)
{
    write("You wash your "+arg+" in the bassin.\n");
    say(this_player()->query_name()+" washes "+
        this_player()->query_possessive()+" "+arg+" in the bassin.\n");
    return 1;
}

int do_sit(string arg)
{
    if (arg!="loo") return 0;
    write("You sit down on the loo.\n");
    say(this_player()->query_name()+" sits down on the loo.\n");
    return 1;
}

int do_tear(string arg)
{
  object paper;

   if (strstr(arg,"paper",0)==-1) return 0;
   write("You tear down a sheat of soft white paper.\n");
   say(this_player()->query_name()+" tears down a sheat of paper.\n");

   paper = clone_object("/obj/treasure");
   paper->set_name("paper");
   paper->set_short("A sheat of soft white paper");
   paper->set_long("A sheat of soft white paper\n");
   paper->set_value(1);
   if (transfer(paper,this_player()))
      move_object(paper,this_object());
   return 1;
}


    

