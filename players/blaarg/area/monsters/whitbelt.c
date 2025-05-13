inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("White Belt Student");
    set_alias("student");
    set_short("A White Belt Student");
    set_long("A student in the Tendo Dojo, beginning his Karate experience.\n");
    set_level(6);
    set_al(250);
    set_hp(150);
    set_gender(1);
    set_race("anime");
    add_money(50);
    set_wc(6);
    set_ac(3);
    set_number_of_arms(4);
}

