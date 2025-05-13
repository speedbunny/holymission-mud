inherit "/room/room";

#include "/room/room_defs.h"
#define WEAPONS   ({"knife","hatchet","hand axe"})
 
void reset(int arg) {
  clone_list = ({
    1, 7, "small orc", "obj/monster", ({
      "set_name", "orc",
      "set_race", "orc",
      "set_alt_name", "small orc",
      "set_level", 1+random(4),
      "set_short", "An orc",
      "set_long", "A disgusting orc, drooling on himself while waiting "+
        "for his next meal.\n",
      "set_al", -60,
      "load_a_chat_array", ({ 30, ({
        "Orc says: Yummy, here comes a little snack !\n",
        "Orc says: Tell Shaggratt to heat the oven !\n",
        "Orc says: Get lost, crap !\n",
        "Orc says: Shall we eat him raw ?\n",
        "Orc says: Bah, I don't like it when the food smells this way.\n"
      }) }),
      "set_move_at_reset", 1,
      "set_aggressive", 1,
    }),
    -1, 1, "axe", "obj/weapon", ({
      "set_name", WEAPONS[random(3)],
      "set_class", 5+random(5),
      "set_value", 15+random(11),
      "set_weight", 1+random(2),
      "set_alt_name", "axe",
      "set_type", 2,
    }),
  });
 
  set_light(1);
 
  short_desc = "The orc fireplace";
  long_desc =
    "You are in the orc valley. It is a narrow valley stretching east "+
    "and west, and is inhabited by orcs "+
    "and ogres. It seems that some of the orcs must've made a "+
    "camp here, judging by the burning fire and the limbs "+
    "and body parts strewn about the place.\n";
 
  dest_dir = ({
    ORC_VALLEY + "valley01", "east",
    ORC_VALLEY + "valley03", "west",
  });
 
  smell = "You smell the disgusting odor of urine and rotting meat.";
 
  items = ({
    "valley", "This is orc valley",
    "camp", "This looks like an orc camp",
    "fire", "A fire is burning slowly in the middle of the camp",
    "limbs", "They look to be mostly human and elven",
    "parts", "They appear to be mainly human",
    "body parts", "They appear to be mainly human",
    "place", "It is a camp",
  });
 
  ::reset(arg);
  replace_program("/room/room");
}

