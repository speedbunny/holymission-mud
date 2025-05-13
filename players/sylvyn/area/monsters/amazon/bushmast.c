inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("bushmaster");
    set_race("reptile");
    set_alt_name("snake");
    set_level(42);
    set_move_at_reset();
    set_ac(20);
    set_wc(15);
    set_al(-750);
    add_money(2000);
    set_short("bushmaster");
    set_long(
    "A Bushmaster is a 12 foot long snake....\n"
    );

}
