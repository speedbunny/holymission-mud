inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("gila monster");
    set_alias("monster");
    set_race("lizard");
    set_move_at_reset();
    set_level(50);
    set_number_of_arms(2);
    set_ac(20);
    set_wc(15);
    set_n_ac(8);
    set_n_wc(10);
    set_al(-500);
    add_money(1200);
    set_short("gila monster");
    set_long(
    "A Gila Monster is up to twenty-four long with a heavy body and tail.\n"
    );
}
