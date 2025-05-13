
/* entrance */

#define COL ({"red","blue","green","white"})

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "At the entrance of Swifto's house";
         long_desc = BS(
         "You are at the entryway of a beautiful house. "+
         "It's a medium sized room with a big wooden door "+
         "to the south. The floor is hardwood and the room "+
         "is lit low by a candle chadelier. About halfway down "+
         "you can see the diningroom. To the north you can "+
         "enter a large deck where you can overlook the lake. "+
         "A wooden stairway is leading up to the bath and bedroom. "+
         "In the middle of the room is an oak wooden table with a "+
         "big vase full of carnations. There is a big picture "+
         "hanging on the wall.");

        items =
        ({
         "walls","The walls are painted in white",
         "floor","The floor is hardwood",
         "ceiling","The ceiling is made of sruce wooden lathes",
         "chadelier","The large golden chadelier lits the room",
         "diningroom","You see a large diningroom halfway down",
         "deck","There is a sundeck to the north",
         "stairway","A big wooden stairway is leading up",
         "table","It's a pretty, big wooden table",
         "vase","The vase is full with pretty carnations",
         "picture",
         "The picture shows a pretty woman and a handsome man.\n"+
         "They are wearing red-golden robes and brown sandales.\n"+
         "The man is holding the woman tightly and kissing her.\n\n"+
         "               An inscription in the picture says: Klimt", 
        });

         dest_dir =
         ({
           PATH+"bedroom","up",
           "/room/south/sshore4","east",
           PATH+"dining_room","down",
           PATH+"deck","north"
         }); 

      }
  }
void init()
{
     ::init();
     add_action("do_get","get");
}

int do_get(string arg)
{
  object mob;

    if (strstr(arg,"carnation",0)==-1) return 0;

    mob = clone_object("/obj/food");
    mob->set_name(COL[random(4)]+" carnation");
    mob->set_alias("carnation");
    mob->set_value(1);
    mob->set_long("A beautiful flower.\n");
    write("You get a carnation from the vase.\n");
    move_object(mob,this_player());
    return 1;
}

    

