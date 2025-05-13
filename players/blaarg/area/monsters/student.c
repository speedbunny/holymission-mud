inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Student");
    set_alias("student");
    set_short("A Student");
    set_long("A student, just trying to learn his lessons.\n");;
    set_level(5);
    set_al(200);
    set_hp(150);
    set_gender(1);
    set_race("anime");
    add_money(50);
    set_wc(5);
    set_ac(2);
    set_number_of_arms(2);
}

