inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("bullfrog");
    set_level(37);
    set_move_at_reset();
    set_ac(5);
    set_alt_name("frog");
    set_al(-500);
    add_money(1000);
    set_short("bullfrog");
    set_long(
    "A Bullfrog is a very large frog.\n"
    );

}
