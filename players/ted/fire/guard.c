#include "/players/ted/defs.h"

inherit "room/room";

object gate_guard, weapon, shield;

init() {
  ::init();
  add_action("do_north"); add_verb("north");
}

reset(arg) {
 int i;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "A Guard Room";
    long_desc =
"This room smells as if a number of unbathed men have spent\n"+
"a very long time here. There are signs of a recently disturbed\n"+
"poker game. Cots and bed rolls lie in one corner of the room.\n";
    dest_dir = ({
FIRE + "gate","south",
FIRE + "courtyard","north"
    });
    items = ({
"bed rolls","These are hard wooden planks covered by a thin layer\n"+
       "of padding. They look very uncomfortable",
"cots","These are hard wooden planks covered by a thin layer\n"+
       "of padding. They look very uncomfortable",
"poker","This is a game played with cards. As the cards are delt, the\n"+
       "people playing bet coins on what their cards are.(Very Primitive)",
"game","This is a game played with cards. As the cards are delt, the\n"+
       "people playing bet coins on what their cards are.(Very Primitive)"
    });
  }
  if(!present("fire giant guard")) {
    i = 0;
    while(i < 3) {
       i ++;
       gate_guard = clone_object("players/ted/monsters/fire_giant_guard");
       move_object(gate_guard, this_object());
       weapon = clone_object("players/ted/weapons/fire_giant_longsword");
       move_object(weapon, gate_guard);
       shield = clone_object("players/ted/armors/fire_giant_shield");
       move_object(shield, gate_guard);
       gate_guard->init_command("wield longsword");
       gate_guard->init_command("wear shield");
       gate_guard->set_ac(6);
       gate_guard->set_wc(20);
    }
  }
}

do_north() {
 if(present("giant")) {
  write("The Fire Giant blocks your way!\n");
  return 1;
 }
}
