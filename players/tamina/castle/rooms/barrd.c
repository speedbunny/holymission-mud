/*  This is the Barracks - Basement  */

inherit "room/room";
#include "/players/tamina/defs.h"

reset(arg) 
{
  if (arg) return;

     set_light(1);
     short_desc = "Barracks -  Basement";
     long_desc =
"The stench of rotten flesh suddenly hits your nose as you step cautiously\n"+
"down the old wooden stairs.  There is very little in this room...\n"+
"Apart from the pieces of bodies that are littering the floor.  \n";     

     dest_dir = ({
   CROOMS + "barracks", "up",
     });

     items = ({
  "pieces",
"There are many small, half-chewed bits of flesh lying strewn "+ 
"across the floor.  Amongst these are pieces of bone and sinew "+
"that don't look very pleasant at all.",
  "floor",
"The floor is covered in rotten flesh, and gnawed bones of what "+
"you would swear were once humans",
      });

      clone_list = ({1,3,"zombie","/obj/monster",
   ({"set_name", "zombie",
     "set_level", 11,
     "set_short", "Zombie",
     "set_long", "A horrific walking corpse, which smells vile...",
     "set_aggressive", 1,
     "set_hp", 500,
     "set_wc", 10,
     "set_ac", 5,
     "set_spell_mess2", "The Zombie smacks you in the face with the stump of his arm!\n",
     "set_spell_mess1", "The Zombie swings his stump violently!!\n",
     "set_spell_dam", 10 + random(40),
     "set_chance", 5,
     "add_money", 150 }),
    });

    ::reset();

    RPR("room/room");
}
