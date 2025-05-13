inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Sensai");
    set_alias("sensai");
    set_short("A Sensai");
    set_long("A master in Karate, the sensai teaches his pupils.\n");
    set_level(20);
    set_al(1000);
    set_hp(450);
    set_gender(1);
    set_race("anime");
    add_money(1000);
    set_wc(17);
    set_ac(13);
    set_number_of_arms(4);
}

