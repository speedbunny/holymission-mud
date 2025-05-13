inherit "obj/monster";
reset (arg) {
    ::reset();
    if (arg) return;
    set_name("zombie");
    set_level(4);
    set_hp(150);
    set_al(-100);
    set_ac(2);
    set_wc(10);
    set_aggressive(1);
    set_race("undead");
    set_short("Zombie");
    set_long("A person made of rotten flesh.\n");
    add_money(random(50));
}
