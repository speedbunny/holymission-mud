

/* kitiaras anteroom */

inherit "/room/room";
#include "defs.h"
#include "/obj/door.h"
 
object door_1, door_2;

void make_doors()
{

       if (!door_2 && door_1)
          destruct(door_1);
       else if (!door_1 && door_2)
          destruct(door_2);

       catch(call_other(PATH+"kitiaras_hall","???"));

       door_1 = clone_object("/obj/door");
       door_1->set_dir("east");
       door_1->set_code("4711");
       door_1->set_type("wooden door");
       door_1->set_room(PATH+"kitiaras_hall");
       door_1->set_closed(1);     
       door_1->set_locked(1);
       door_1->set_can_lock(1);

       door_2 = clone_object("/obj/door");
       door_2->set_dir("west");
       door_2->set_type("wooden door");
       door_2->set_room(PATH+"kitiaras_anteroom");
       door_1->set_door(door_2);
       door_2->set_door(door_1);
       door_1->set_both_status();
}

void reset(int flag)
{
    if (flag == 0)
    {
     short_desc = "You are in Kitiaras anteroom";
     long_desc = BS(
         "You are in Kitiaras anteroom, in Kantele's castle. " +
         "A dirty passage leads to the south and west. "+
         "There is a sign fixed to the western wall.");
     dest_dir = ({
                  PATH+"kitiaras_crossing","south",
                 });
     items =
     ({	
        "sign","The sign says\n\n"+
               "MORTALS SHOULD NOT ENTER !(on pain of death.)",
      });
      if (!door_1)
          make_doors();
    }
    door_1->set_closed(1);     
    door_1->set_locked(1);
    door_1->set_both_status();
}

void is_door_here()
{
   if (!door_1 || !door_2)
        make_doors();
}

void init()
{
   ::init();
   is_door_here();
}

