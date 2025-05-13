inherit "obj/monster";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    
    set_name("black panther");
    set_alias("panther");
    set_race("panther");
    set_number_of_arms(2);
    set_move_at_reset();
    set_level(50);
    set_ac(20);
    set_n_wc(15);
    set_sp(0);
    set_al(-1000);
    add_money(1500);
    set_short("black panther");
    set_long(
    "A large black muscular panther that thinks you're its next meal!\n");
}
