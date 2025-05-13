inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Black Belt Student");
    set_alias("student");
    set_short("A Black Belt Student");
    set_long("A student in the Tendo Dojo, mastering the art of Karate.\n");
    set_level(18);
    set_al(750);
    set_hp(350);
    set_gender(1);
    set_race("anime");
    add_money(500);
    set_wc(11);
    set_ac(7);
    set_number_of_arms(4);
}

