/*  This is the North_West Tower -- 1st floor  */

#include "/players/tamina/defs.h"

inherit "room/room";

void reset(int arg) {

  if(arg) return;

     set_light(1);
     short_desc = "North-West Tower -- First floor";
     long_desc =
"As you mount the winding stone stairs, the awful stench seems to dissipate\n"+
"slightly.  This room would appear to have been a simple floor in the tower\n"+
"that you are at the moment climbing. \n";     
  
     dest_dir = ({
   CROOMS + "nw_tower3", "up",
   CROOMS + "nw_tower", "down",
     });

     clone_list = ({1, 3, "guard", "obj/monster", 
  ({"set_name", "guard",
    "set_level", 21,
    "set_short", "Morgan's Guard",
    "set_long", "A tall figure who will follow his Master's orders well.\n",
    "set_aggressive", 1,
    "set_hp", 890,
    "set_wc", 25,
    "set_ac", 13  }),
        -1, 1, "mail", "obj/armour",
  ({"set_name", "chainmail",
    "set_alias", "mail",
    "set_short", "Guard's Chainmail",
    "set_long", "A set of reasonably well-made chainmail, but looks to be\n"+
                "made from a strange alloy, which you cannot identify.\n",
    "set_weight", 4,
    "set_size", 3, 
    "set_ac", 3, 
    "set_value", 900,
    "set_type", "armour"  }),
        -1, 1, "helmet", "obj/armour",
   ({"set_name", "helmet",
     "set_alias", "helm",
     "set_short", "Guard's Helmet",
     "set_long", "A fine helmet made out of a strange black metal.\n",
     "set_weight", 2,
     "set_size", 3, 
     "set_ac", 1,
     "set_value", 200,
     "set_type", "helmet"  }),
         -1, 1, "shield", "obj/armour",
   ({"set_name", "shield",
     "set_short", "Guard's Shield",
     "set_long", "A well-crafted shield made out a weird black material.\n",
     "set_weight", 2,
     "set_size", 3, 
     "set_ac", 1, 
     "set_value", 350,
     "set_type", "shield"   }),
         -1, 1, "scimitar", "obj/weapon",
   ({"set_name", "scimitar",
     "set_alias", "sword",
     "set_short", "Black Scimitar",
     "set_long", 
"A wicked, curving blade crafted from a strage black metal that you\n"+ 
"do not recognise.  It has a set of runes etched into one side of \n"+
"the blade.\n",
     "set_class", 17,
     "set_weight", 4,
     "set_value", 2500,
     "set_read", "You cannot understand the runes at all.\n"  }),  
   });

    ::reset();

    RPR("room/room");
}
