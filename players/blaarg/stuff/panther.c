inherit "obj/monster";



reset(arg) {
    ::reset(arg);
    if(arg)return;
    set_name("Black Panther");
    set_alias("panther");
    set_race("panther");
    set_gender(1);
    set_number_of_arms(2);
    set_level(40);
    set_str(40);
    set_dex(40);
    set_ac(10);
    set_wc(15);
    set_hp(2000);
    set_sp(0);
    set_al(-1000);
    add_money(1500);
    set_short("black panther");
    set_long(
      "A large black panther that thinks your it's main course of the day!\n");

}
