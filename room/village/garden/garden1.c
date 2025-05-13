inherit "/room/room";
 
#include "/room/room_defs.h"

void reset(int arg) {
  clone_list = ({
    1, 4, "bee", "obj/monster", ({
      "set_name", "honey bee",
      "set_alt_name", "bee",
      "set_race", "insect",
      "set_short", "A honey bee",
      "set_long", "A yellow and brown striped honey bee. It is flying "+
        "from flower to flower.\n",
      "set_level", 1,
      "set_size", 1,
      "load_chat_array", ({ 8, ({
        "SUMMMM ...\n",
        "BUZZZZ ...\n",
        "A little bee flies around your head.\n"
      }) }),
    }),
    -1, 1, "honey", "obj/food", ({
      "set_name", "honey",
      "set_short", "Some delicious honey",
      "set_long", "This is some honey from a bee. It looks very tasty.\n",
      "set_value", 5,
      "set_weight", 1,
      "set_strength", 3,
      "set_eater_mess", "YUMMI! That tastes sweet!\n",
      "set_eating_mess", " slurps down some delicious honey.\n",
    }),
  });

  set_light(1);
  short_desc = "In a beautiful garden";
  no_castle_flag = 0;

  long_desc =
    "You have entered Chantilly's beautiful garden. " +
    "This southwestern portion is very beautiful with all "+
    "the various flowers arranged here. The town wall "+
    "is directly south and the garden stretches north and "+
    "east. The garden entrance is to the west.\n";

  items = ({
    "garden", "This part of the garden is filled with flowers",
    "flowers", "There are many different kinds, including "+
      "columbine, hollyhock, buttercups, geraniums and lilies",
    "wall", "The town wall prevents going south and is too "+
      "difficult to climb",
    "entrance", "It is to the west",
  });

  property = ({ "no_teleport" });

  dest_dir = ({
    VILLAGE_GARDEN + "garden4", "north",
    VILLAGE_GARDEN + "garden2", "east",
    VILLAGE_GARDEN + "entrance", "west",
  });

  ::reset(arg);
  replace_program("room/room");
}

