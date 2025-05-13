inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Brown Belt Student");
    set_alias("student");
    set_short("A Brown Belt Student");
    set_long("A student in the Tendo Dojo, furthering his Karate experience.\n");
    set_level(12);
    set_al(500);
    set_hp(250);
    set_gender(1);
    set_race("anime");
    add_money(200);
    set_wc(8);
    set_ac(5);
    set_number_of_arms(4);
}

