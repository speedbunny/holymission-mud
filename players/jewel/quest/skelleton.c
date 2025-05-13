inherit "obj/monster";

reset (arg) {
    ::reset(arg);
    if (arg) return;
    set_name("skeleton guard");
    set_alt_name("guard");
    set_alias("skeleton");
    set_level(3);
    set_hp(100);
    set_al(-50);
    set_ac(4);
    set_wc(7);
    set_aggressive(1);
    set_race("undead");
    set_short("A Skeleton");
    set_long("A ratteling pile of bones.\n");
}
