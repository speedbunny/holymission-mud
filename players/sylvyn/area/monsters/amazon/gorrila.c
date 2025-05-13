inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_name("Silverbacked Gorilla");
    set_alias("gorilla");
    set_race("gorilla");
    set_move_at_reset();
    set_number_of_arms(2);
    set_level(55);
    set_ac(35);
    set_wc(20);
    set_sp(0);
    set_al(-500);
    add_money(1500);
    set_short("Silverbacked Gorila");
    set_long(
    "This is a REALLY big and REALLY strong gorilla. It looks to\n" +
    "really mad!!\n"
    );
}
