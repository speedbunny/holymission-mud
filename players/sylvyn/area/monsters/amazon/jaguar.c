inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("Jaguar");
    set_alias("jaguar");
    set_race("cat");
    set_move_at_reset();
    set_number_of_arms(2);
    set_level(45);
    set_ac(15);
    set_wc(20);
    set_sp(0);
    set_al(-500);
    add_money(1500);
    set_short("A Sleek Jaguar");
    set_long(
    "A sleek powerful Jaguar. A mighty hunter it is and you have\n"
    "become it's next target!!\n"
    );
}
