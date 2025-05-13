inherit "obj/monster";


void rest(int arg) {
    ::reset(arg);
    if(arg)return;

    set_name("anacanda");
    set_alias("ana");
    set_level(40);
    set_move_at_reset();
    set_wc(5);
    set_ac(10);
    set_race("reptile");
    set_alt_name("snake");
    set_al(-500);
     add_money(1500);
    set_short("anacanda");
    set_long(
      "An Anacanda is a long fat snake....\n"
    );
}
