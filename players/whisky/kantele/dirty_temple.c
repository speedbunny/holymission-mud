
inherit "/room/room";
#include "defs.h"

object fiend;

void reset(int flag)
{
        if (!fiend) 
        {
           fiend = clone_object("obj/monster");
           call_other(fiend, "set_name", "pit fiend");
           call_other(fiend, "set_alt_name", "pit");
           call_other(fiend, "set_alias", "fiend");
           call_other(fiend, "set_race", "demon");
           call_other(fiend, "set_level",60);
           call_other(fiend, "set_al", -300);
           call_other(fiend, "set_short", "A huge Pit Fiend is here");
           call_other(fiend, "set_aggressive", 1);
           call_other(fiend, "set_wc",35);
           call_other(fiend, "set_ac",15);
           call_other(fiend, "set_number_of_hands",6);
           call_other(fiend, "set_chance",80);
           call_other(fiend, "set_spell_mess1",
               "The Pit Fiend casts a firebolt at you.");
          call_other(fiend, "set_spell_mess2",
                "You are hit by a firebolt");
          call_other(fiend, "set_spell_dam",60+random(80));
          move_object(fiend,this_object());
      }

      if (flag == 0)
      {
          dest_dir =
          ({
             PATH+"dirty_anteroom","north",
/* commented out because the room behind_altar is buggy 
             PATH+"behind_altar","south",
     */
             PATH+"on_bridge.c","west",
           });

         short_desc = "In the Evil Temple";
         long_desc = BS(
         "You are in a Evil Temple, behind the altar to the south you can " +
         "see a huge statue of Kali. To the west a rickety bridge leads " +
         "into the darkness. The bridge looks very frail.");
         items =
         ({
          "statue","The statue of evil Kali",
          "bridge","The bridge leads into the darkness",
          "walls","The walls are made of red bricks",
          "ceiling","The ceiling is made of red bricks",
          "bottom","The bottom is made of fouly wood",
         });
      }
 }

