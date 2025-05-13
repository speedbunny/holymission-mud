

/* kitiaras anteroom */

inherit "/room/room";
#include "defs.h"
#include "/obj/door.h"
 
object door_1, door_2;

void make_doors(int x)
{
     if (x==1)
     {
       door_1 = clone_object("/obj/door");
       door_1->set_dir("east");
       door_1->set_code("4711");
       door_1->set_type("wooden door");
       door_1->set_room(PATH+"kitiaras_hall");
       door_1->set_closed(1);     
       door_1->set_locked(1);
       door_1->set_both_status();
       move_object(door_1,this_object());
     }
     else if (x==2)
     {
       catch(call_other(PATH+"kitiaras_hall","???"));
       door_2 = clone_object("/obj/door");
       door_2->set_dir("west")
       door_2->set_code("4711")
       door_2->set_type("wooden door")
       door_2->set_room(PATH+"anteroom_hall");
       door_2->set_closed(1);     
       door_2->set_locked(1);
       door_2->set_both_status();
       move_object(door_2,PATH+"anteroom");
    }
}

void reset(int flag)
{
    if (flag == 0)
    {
     short_desc = "You are in Kitiaras anteroom";
     long_desc = BS(
         "You are in Kitiaras anteroom, in Kantele's castle. " +
         "A dirty passage leads to the east and west. "+
         "There is a sign fixed to the western wall.");
     dest_dir = ({
                  PATH+"cellar_west.c", "east",
                 });
     items =
     ({	
        "sign","The sign says\n\n"+
               "MORTALS SHOULD NOT ENTER !(on pain of death.)",
      });
    }
    if (!door_1)
        make_doors(1);
    if (!door_2)
        make_doors(2);
}

