inherit "room/room";

object shaman;

int fix_shaman() {

    object gold_stick,orc_slayer;

    if (!shaman || !living(shaman)) {
        gold_stick = clone_object("obj/staff");
        orc_slayer = clone_object("obj/weapon");
        orc_slayer->set_name("short sword");
        orc_slayer->set_alias("sword");
        orc_slayer->set_short("Short sword");
        orc_slayer->set_alt_name("orc slayer");
        orc_slayer->set_long("This is a very fine blade.\n"+
                             "It's covered with ancient runes.\n" + 
                             "Engraved on it is a picture of the " +
                             "sword slicing an orc.\n");
        orc_slayer->set_read("The only thing you can read is " +
                             "the word 'orc'.\n");
        orc_slayer->set_class(9);
        orc_slayer->set_weight(2);
        orc_slayer->set_value(200);
        orc_slayer->set_hit_func(this_object());
        shaman = clone_object("obj/monster");
        shaman->set_name("shaman");
        shaman->set_alias("orc shaman");
        shaman->set_race("orc");
        shaman->set_level(10);
        shaman->set_size(3);
        shaman->set_al(-300);
        shaman->set_short("An orc shaman");
        shaman->set_wc(10);
        shaman->set_ac(1);
        shaman->set_aggressive(1);
        shaman->set_chance(20);
        shaman->set_spell_mess1("You are hit by a magic missile.");
        shaman->set_spell_mess2("The shaman casts a magic missile.");
        shaman->set_spell_dam(20);
        move_object(shaman, this_object());
        move_object(gold_stick, shaman);
        move_object(orc_slayer, shaman);
    }
    return 1;
}

int weapon_hit(object attacker) {
    if(attacker->query_race()=="orc") {
        write("The orc slayer glows in a cold blue light.\n");
        return 10;
    }
    return 0;
}

void reset(int arg) {

    set_light(1);

    short_desc="The orc treasury";

    long_desc="You are in the orc treasury. It is normally heavily guarded.\n";

    dest_dir=({"room/fortress", "south"});

    items=({"treasury","Maybe there's still some treasure around"});

    fix_shaman();

    ::reset(arg);
    replace_program("room/room");
}
