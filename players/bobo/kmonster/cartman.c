inherit "obj/monster";

object attacker;

reset(arg) {

    ::reset(arg);
    if (arg) return;

    set_name("man");
    set_alias("cartman");
    set_short("A man");
    set_long("He drives this carriage.\n");
    set_race("human");
    set_male();
    set_size(3);
    set_level(15);
    set_ac(2);
    set_wc(7);
    add_money(200);
    set_al(100);
}

