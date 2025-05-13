inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("baboon");
    set_race("monkey");
    set_move_at_reset();
    set_level(35);
    set_wc(5);
    set_ac(10);
    set_al(-500);
    add_money(1000);
    set_short("A small baboon");
    set_long(
    "A small cute looking baboon. He doesn't seem to notice\n"
    "you are around.\n"
    );
}
