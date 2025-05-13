

/* ob_bridge */

inherit "/room/room";
#include "defs.h"

object ogre;

void reset(int flag)
{
     ::reset(flag);
     if (!ogre) 
     {
         ogre  = clone_object("obj/npc");
         call_other(ogre, "set_name", "troll");
         call_other(ogre, "set_alt_name","large troll");
         call_other(ogre, "set_level",40);
         call_other(ogre, "set_hp",800);
         call_other(ogre, "set_whimpy", -1);
         call_other(ogre, "set_short", "A large Troll is here");
         call_other(ogre, "set_wc",50);
         call_other(ogre, "set_ac",15);
         call_other(ogre, "set_attacks",3);
         call_other(ogre, "set_attacks_change",50);
         call_other(ogre, "add_money", random(1000)+3000);
         move_object(ogre, this_object());
     }
     if (flag == 0)
     {
         set_light(0);
         short_desc = "Besides a ricket wooden bridge";
         long_desc = BS(
         "You are standing besides a rickety wooden bridge in Kantele's "
         "castle. The bridge extends across the chasm to the west " +
         "vanishing into the darkness.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "bridge","A ricket wooden bridge",
         });
         dest_dir =
         ({
             PATH+"west_bridge","west",
             PATH+"dirty_temple","east",
         });
      }
}

int move(string arg)
{
    if (!arg)
        arg = query_verb();

    if (arg == "west" && ogre && living(ogre))
    {
        command("say no way to pass me !",ogre);
        return 1;
    }
   return ::move(arg);
}
