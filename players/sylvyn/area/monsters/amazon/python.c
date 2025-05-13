inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("python");
    set_race("reptile");
    set_alt_name("snake");
    set_move_at_reset();
    set_level(45);
    set_ac(20);
    set_wc(15);
    set_al(-500);
    add_money(1200);
    set_short("python");
    set_long(
    "A Python is a very long snake, with large fangs.\n"
    );

}
