

/* ---------------------------------------------------------------------
   filename: visitors_shop.c last edit: 7.2.94 whisky uni-linz.ac.at 
   --------------------------------------------------------------------- */

inherit "/players/whisky/obj/std_shop";
#include "../guild.h"

int i;
int x;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the monkshop";
  long_desc = BS(
  "You have entered a small dusty room. The walls are made of red "+
  "bricks and the floor is made of spruce wooden lathes. This is the "+
  "place where Danica the nun, who is standing behind a desk, trades "+
  "with all kinds of stuff. There is a sign saying: 'type list' behind "+
  "his desk.");
  set_light(1);
   store = "/players/whisky/guild/room/vstore";
   keeper = "Danica";

  items = ({"walls","The walls are made of red bricks",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
            "danica","She is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/whisky/guild/room/visit","east" });

    if (!present("torch",query_store()))
    {
        for(x=0;x<5;x++)
        {
            move_object(clone_object("/players/whisky/obj/torch"),
                        query_store());
        }
     }
    if (!present("blue scroll",query_store()))
    {
        for(x=0;x<7;x++)
        {
            move_object(clone_object("/players/whisky/obj/recall_scroll"),
                        query_store());
        }
   }
    if (!present("rucksack",query_store()))
    {
        for(x=0;x<3;x++)
        {
            move_object(clone_object("/players/whisky/seaworld/obj/rucksack"),
                        query_store());
        }
   }

  if (!present("trashcan",this_object()))

  if (!present("trashcan",this_object()))
     move_object(
          clone_object("players/whisky/shops/trashcan"),this_object());
}

query_property(arg) 
{
   return arg=="no_fight";
 }

/* moved out 

int buy_object(string arg)
{
    if (!present("matchbox",query_store()) || 
        !present("torch",query_store() )  )
    {
        write(keeper+" tells you: Wait a second I get one from the store.\n");
      if (!present("matchbox",query_store()))
      {
        move_object(clone_object("/players/galadriel/fire/matchbox"),
                    query_store());
      }
      else
       move_object(clone_object("/obj/torch"),query_store());
    }
   return ::buy_object(arg);
}

int get_list(string arg)
{
    if (::get_list(arg))
    {
       write(
       "Even if not in my list, I can get you a matchbox a torch,\n"+
       "a blue scroll or a rucksack from the store.\n");
       return 1;
    }
   return 0;
}
     */
