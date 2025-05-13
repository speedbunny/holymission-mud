
/* uc6 */

inherit "/room/room";
#include "../guild.h"

object zenzi;
int count;

void reset(int flag)
{
   object tre;
   int i;

   count = 0;

   if (!zenzi)
   {
       move_object(clone_object("/players/whisky/guild/monster/zenzi"),
       this_object());
   }
   if (!present("cheese",this_object()))
   {
       for (i=0; i < 4; i++)
       {
          tre = clone_object("/obj/food");
          tre->set_name("cheese");
          tre->set_short("cheese");
          tre->set_amount(3);
          tre->set_value(20);
          move_object(tre,this_object());
        }
    }
           
   if (!present("potion",this_object()))
   {
       for (i=0; i < 2; i++)
       {
        move_object(clone_object("/players/whisky/obj/bless_potion"),
                    this_object());
        }
        move_object(clone_object("/players/whisky/obj/invis_potion"),
                    this_object());
   }
   if (!present("money",this_object()))
   {
        tre = clone_object("/obj/money");
        tre->set_money(450+random(50));
        move_object(tre,this_object());
    }

    if (filter_live(this_object()) < 4)
        CM("centipede");

     if (flag == 0)
     {
      short_desc = "In a cave under the monk chapel";
      long_desc = BS(
      "You have entered the place where the goblins hide "+
      "their treasure and food. This place is wet and it "+
      "smells a bit fouly. The walls are covered by red "+
      "moss. In one of the corners there is some wet 'rubble'. "+
      "The only way out is to the west.");

      property = "no_teleport";

      items = ({
      "bottom","The bottom is wet and covered with moss",
      "ground","The bottom is wet and covered with moss",
      "walls","The walls are wet, heavy granite blocks",
      "wall","The walls are wet, heavy granite blocks",
      "moss","The moss has a light green colour",
      "ceiling","Some water is driping from the ceiling",
      "rubble","Some wet rubble, hmm maybe a good place to hide something",
      "centipedes","As you look at them they quickly hide under a stone",
         });

      dest_dir = ({
                 PATH+"uc5","west"
                 });
     }
  }

void init()
{
    add_action("fcn_search","search");
    ::init();
}

int fcn_search(string arg)
{
   object key;

    say(this_player()->query_name()+" searches around.\n",this_player());

    if (arg!="rubble")
    {
        write("You search around but find nothing.\n");
        return 1;
    }
    else if (count)
    {
        write("You find nothing, it seems someone was faster.\n");
        return 1;
    }
    write("Klick, a key slips through your fingers and falls to the ground.\n");
    key = clone_object("/obj/treasure");
    key->set_name("key");
    key->set_alias("zenzi_key");
    key->set_short("key");
    key->set_long("A small iron key.\n");
    key->set_value(10);
    move_object(key,this_object());
    count = 1;
    return 1;
}


 
