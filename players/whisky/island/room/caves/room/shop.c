


/* orc shop */

inherit "/players/whisky/obj/std_shop";
#include "../caves.h"

int i;
int x;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the Orc shop";
  long_desc = BS(
  "You have entered a small cave-in in the orc's cave where "+
  "Gulash the orc sells all kinds of stuff. The walls are painted "+
  "with human blood and there is a sign grunting: 'type list' "+
  "behind the counter. A small corridor is leading back to the west.");
   set_light(1);
   store = PATH+"store";
   keeper = "Gulash";

  items = ({"walls","The walls are painted in human blood",
            "desk","It's a wooden desk",
            "gulash","He is standing behind the counter grunting at you",
            "sign","The sign says: Type list fucker !"
            });

    dest_dir = ({ PATH+"ci6","west" });

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
