inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("monkey");
    set_race("monkey");
    set_number_of_arms(2);
    set_move_at_reset();
    set_level(33);
    set_ac(10);
    set_wc(10);
    set_al(-750);
    add_money(1300);
    set_short("monkey");
    set_long(
    "This is a small monkey, it looks rather harmless.\n"
    );

}
