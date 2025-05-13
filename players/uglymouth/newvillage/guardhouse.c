/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "Headquarters of the local militia";
  long_desc = "This building holds the headquarters of the local militia. A table and\n"
        + "some chairs stand in the room and a cupboard hangs in a corner. In the\n"
        + "north wall is a door with a barred window.\n";
  dest_dir = ({ PATH+"street2","south" });
  items = ({"building","A wooden building, like most others in this village",
        "table","A deck of cards lies on it",
        "deck","A normal deck of cards, to pass the time",
        "chairs","Ordinary wooden chairs",
        "cupboard","An small cupboard, containing some empty mugs",
        "door","The reinforced wooden door suggests some kind of prison",
        "prison","Look through the window if you want to see it",
        "window","@@look_window@@",
        });

  clone_list = ({ 1, 1+random(3), "guard", "obj/monster",
      ({ "set_name", "village guard",
         "set_alias", "guard",
         "set_level", 1 + random(3),
         "set_gender", 1 + random(2),
         "set_race", "human"
         }),
      -1, 1, "spear", "obj/weapon",
      ({ "set_name", "spear",
         "set_class", 7,
         "set_value", 30
         }),
      -1, 1, "cloak", "obj/armour",
      ({ "set_name", "cloak",
         "set_ac", 1,
         "set_short", "A simple cloak",
         "set_type", "cloak",
         "set_value", 75
         })
      });
  ::reset();

  }

string look_window(string str) {
string desc,sdesc;
object prison,ob;
  desc = ("/room/prison")->long();
/*
  prison = find_object("/room/prison");
  ob = first_inventory(prison);
  while(ob) {
    if(sdesc = ob->short()) desc = desc + sdesc + "\n";
    ob = next_inventory(prison);
    }
*/
  return desc;
  }
