inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("salamander");
    set_race("lizard");
    set_move_at_reset();
    set_level(34);
    set_ac(10);
    set_wc(5);
    set_al(-500);
    add_money(1400);
    set_short("salamander");
    set_long(
    "This is a Salamander, another harmless looking animal in this forest.\n"
    );

}
