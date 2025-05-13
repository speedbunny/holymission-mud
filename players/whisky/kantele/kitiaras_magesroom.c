
inherit "/room/room";
#include "defs.h"

object mage;

void reset(int flag)
{
        if (!mage) 
        {
           mage = clone_object("obj/monster");
           mage->set_name("necromancer");
           mage->set_alias("mage");
           mage->set_level(19);
           mage->set_hp(350);
           mage->set_al(-300);
           mage->set_short("A black robed necromancer is here");
           mage->set_wc(19);
           mage->set_ac(10);
           mage->set_aggressive(1);
           mage->set_chance(50);
           mage->set_spell_mess1("casts a fireball.");
           mage->set_spell_mess2(
                "You are hit by a fire ball.");
           mage->set_spell_dam(40);
        }
        if (flag == 0)
        {
         dest_dir =
         ({
            PATH+"kitiaras_lab","south",
         });

         short_desc = "In the mages room.";
         long_desc = BS(
         "In the mages room, this little room only contains a small bed.");
         items = ({
         "bottom","The bottom is made of fouly wood",
         "ceiling","The ceiling is made of red bricks",
         "walls","The walls are made of red bricks",
         "bed","A really small bed much too small to enter",
         });
      }
  }


