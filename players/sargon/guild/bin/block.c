#include "/players/sargon/define.h"

#define DEX	TP->query_dex()
#define STR	TP->query_str()

int check_sp() {
    if(TP->query_spell_points() > 7) {
        return 1;
    }
    else {
        write("You are too tired to block.\n");
        command("lower", TP);
        return 0;
    }
}

int reduce_sp() {
    if(TP->query_attack() &&
       present("block-armour", TP) &&
       check_sp()) {
        TP->restore_spell_points(-2);
        call_out("reduce_sp", 5);
        return 1;
    }
    else
        return 0;
}

int block() {
    object att, arm, *arr, ob;
    int i, j, k, z, ac, power, level;

    k = 0;

    att = TP->query_attack();
    if(!att) {
        write("You are not fighting.\n");
        return 1;
    }
    else
        ob = present("shield", TP);

    if(!ob) {
        write("You need a shield to block!\n");
        return 1;
    }
    else if(!ob->query_worn()) {
        write("You must wear your shield to block!\n");
        return 1;
    }
    else if(TP->berzerk_shad()) {
        write("You cannot block while in a berzerker rage!\n");
        return 1;
    }
    else
        arm = present("block-armour", TP);

    if(arm) {
        write("But you are already blocking!\n");
        return 1;
    }
    else
        arr = all_inventory(TP);

    j = sizeof(arr);
    for(i = 0; i < j; i++) {
        if(arr[i]->query_wielded())
            k++;
    }
    if(k > 1) {
        write("You are wielding two weapons!\n");
        return 1;
    }
    else if(check_sp()) {
        arm = CO("/players/sargon/guild/obj/block_armour");
        MO(arm, TP);
        power = ((DEX + STR)/3);
        level = TP->query_level();
        ac = (power + level);
        arm->set_ac(ac);
        command("wear block-armour", TP);
        if(reduce_sp())
            write("You begin blocking.\n");
        else
            write("Something went wrong.\n");
    }
    return 1;
}
