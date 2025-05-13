#include "../../room/std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
object tmcat, weapon;
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
extra_init() { add_action("north", "north"); }
 
TWO_EXIT("players/animal/evil17","west",
         "/players/animal/evil19", "north",
         "The tomcat's lair",
         "\n" +
         "    A giant tomcat makes his home here.\n" +
         "    You see the bones of small animals scattered about.\n" +
         "    The tunnel continues to the north here into darkness.\n"+
         "\n", 0)
 
 
extra_reset()  {
               if (!tmcat || !living(tmcat)) {
         tmcat = clone_object("obj/monster");
         call_other(tmcat, "set_name", "tomcat");
         call_other(tmcat, "set_alias", "cat");
         call_other(tmcat, "set_race", "cat");
         call_other(tmcat, "set_level", 8);
         call_other(tmcat, "set_hp", 230);
         call_other(tmcat, "set_al", -200);
         call_other(tmcat, "set_short", "A fat old tomcat");
         call_other(tmcat, "set_ac", 5);
         call_other(tmcat, "set_wc", 12);
         call_other(tmcat, "set_aggressive", 0);
         weapon = clone_object("obj/weapon");
         call_other(weapon, "set_name", "claw");
         call_other(weapon, "alt_alias", "claw");
         call_other(weapon, "set_short", "A wicked cat's claw");
         call_other(weapon, "set_long",
         "This claw looks sharp, and has seen a lot of use.\n");
         call_other(weapon, "set_class", 11);
         call_other(weapon, "set_value", 850);
         call_other(weapon, "set_weight", 2);
         transfer(weapon, tmcat);
 move_object(tmcat, this_object());
          }
}
 
north() {
    if (tmcat && present(tmcat, this_object())) {
     write("The tomcat growls and hisses: 'LEAVE!'\n");
     return 1;
    }
    call_other(this_player(), "move_player", "north#players/animal/evil19");
    return 1;
}
 
 
