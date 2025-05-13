inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Bather");
    set_alias("bather");
    set_short("A Bather");
    set_long("A person bathing in the water, minding his own business.\n");
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

