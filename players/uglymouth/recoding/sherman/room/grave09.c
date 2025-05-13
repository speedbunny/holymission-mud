#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  clone_list = ({
    1, 5, "skeleton", "obj/monster", ({
      "set_name", "dancing skeleton",
      "set_alias", "skeleton",
      "set_alt_name", "undead",
      "set_short", "A dancing skeleton",
      "set_long", "A ratteling pile of bones with an evil grin on its "
        + "skull. It is entranced in a Dance Macabre, in which it "
        + "accompanies itself with the staccato rhythms of its bones, "
        + "used as bizarre castanets.\n",
      "set_level", 3,
      "set_hp", 100,
      "set_race", "undead",
      "set_al", -50,
      "set_ac", 4,
      "set_wc", 7,
      "set_aggressive", 1,
    }),
  });
  short_desc = "A badly disturbed grave.";
  long_desc = "You are standing in front of a badly disturbed grave. Its "
    + "surface is full of strange marks and the tomb stone has been "
    + "shattered. An evil feeling hangs as an uneasy presence in the air.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry6", "south",
  });
  no_obvious_msg = "The gravel path lies directly south of this grave.\n";
  items=({
    "grave", 
      "It looks like the dead have become very restless in this place",
    "surface", "The top layer of clay has been disturbed a lot, with many "
      + "clear marks left",
    "marks", "They seem to be some kind of foot prints, made up of one "
      + "thick part at one end and five thinner ones at the other",
    "tomb stone", "It has been shattered. Shards are now scattered over "
      + "its already disturbed surface",
  });
  property = "Marushka";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
