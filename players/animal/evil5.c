#include "std.h"
 
object treasure, weapon, manx;
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
#undef EXTRA_MOVE2
#define EXTRA_MOVE2\
      if (manx && present(manx)) {\
      write("The Manx screams: 'NO!!!!!!! LEAVE NOW!!!!!'\n");\
      return 1;\
}
 
TWO_EXIT("players/animal/evil4", "south",
 "players/animal/evil8", "up",
 "The lair of the Manx",
 "The lair\n" +
 "\n" +
 "    This room is filled with bones of dead adventurers!\n" +
 "    A VERY nasty cat lives here. The dreaded Manx!\n" +
 "\n", 0)
 
extra_reset() {
    if (!manx || !living(manx)) {
    manx = clone_object("obj/monster");
       call_other(manx, "set_name", "manx");
       call_other(manx, "set_alias", "cat");
       call_other(manx, "set_level", 16);
       call_other(manx, "set_hp", 350);
       call_other(manx, "set_short", "A manx");
       call_other(manx, "set_wc", 17);
	manx->set_fear(1);
       call_other(manx, "set_ac", 6);
       call_other(manx, "set_al", -400);
       call_other(manx, "set_aggressive", 1);
       call_other(manx, "set_chance",25);
	manx->set_steal(1);
       call_other(manx, "set_spell_mess1",
                  "The manx casts a deadly spell.");
       call_other(manx, "set_spell_mess2",
                  "The manx wounds you with a deadly spell.");
       call_other(manx, "set_spell_dam",15);
       move_object(manx, this_object());
       weapon = clone_object("obj/weapon");
       call_other(weapon, "set_name", "unholy sword");
       call_other(weapon, "set_short", "A glowing black sword");
       call_other(weapon, "set_alias", "sword");
       call_other(weapon, "set_long",
"It is a sword of fine workmanship, it is so evil it absorbs light.\n");
        call_other(weapon, "set_class", 17);
        call_other(weapon, "set_value", 5400);
        call_other(weapon, "set_weight", 3);
        call_other(weapon, "set_hit_func", this_object());
        call_other(weapon, "set_wield_func", this_object());
	weapon->set_two_hands(1);
        transfer(weapon, manx);
        treasure = clone_object("obj/treasure");
        call_other(treasure, "set_id", "emerald");
        call_other(treasure, "set_alias", "gem");
        call_other(treasure, "set_short", "A giant emerald");
        call_other(treasure, "set_weight", 3);
        call_other(treasure, "set_value", 500);
        move_object(treasure, manx);
    }
}
 
spellfail(arg) {
    if (!manx || !living(manx)) return 0;
    if (arg && arg != "manx") return 0;
    write ("That bounces off the Manx's thick hide.\n");
    return 1;
}
 
weapon_hit(target) {
    int i;
    i = (call_other(this_player(),"query_alignment",0) -
        call_other(target,"query_alignment",0));
    if (i < -1500) /* negative attack */ {
    write("The blade senses good and hits hard!\n");
    return 5;
    }
    return 0;
}
 
wield(arg) {
    int i;
    if (call_other(this_player(), "query_alignment",0) > -300) {
        write("Only a very evil person may wield the unholy avenger.\n");
        return 0;
    }
    write("You wield the unholy avenger!\n");
    write("You feel the evil ebbing throughout your body.\n");
    write("You feel this sword was made to kill good monsters.\n");
    return 1;
}
 
 
extra_init() {
    add_action("spellfail","fireball");
    add_action("spellfail","bolt");
    add_action("spellfail","fear");
    add_action("spellfail","pacify");
    add_action("spellfail","howl");
    add_action("spellfail","calm");
}
query_no_sneak() { return 1; }
