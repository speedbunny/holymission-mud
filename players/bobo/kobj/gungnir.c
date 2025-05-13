inherit "obj/weapon";
#include "/players/mangla/defs.h"

int magic_hit(object attacker);

int weapon_hit(object attacker) {
    int magdam;

    magdam = magic_hit(attacker);
    attacker->hit_player(magdam,5,0);
    return class_of_weapon*4;
}

int magic_hit(object attacker) {

    if ((wielded_by->query_dex()<15) && random(2)) {
        write("You hurt Gungnir because of your low dexterity, he gives you "+
              "an bolt of electricity.\n");
        return random(15);
    }
    if ((wielded_by->DEX >= 20) && random(2)) {
        write("Gungnir is in a good mood. He hurls " + attacker->NAME + " into the air,\n" +
              "and throws " + attacker->PRO + " to the " + " ground.\n");
    return random(40);
    }
    return 0;       /* !!!! what did you think as you coded that ??? */
}

void reset(int arg) {

    set_name("gungnir");
    set_alias("spear");
    set_class(13);
    set_weight(3);
    set_value(6250);
    set_short("Gungnir");
    set_long("Gungnir is Odin's spear.\n" +
             "It's a powerful weapon if you know how to use it.\n" +
             "Otherwise it could be dangerous to fight with it.\n");
    set_hit_func(TO);
}

