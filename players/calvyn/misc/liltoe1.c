inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("little toe");
    set_short("little toe");
    set_alias("toe");  
    set_gender(random(1));
    set_level(29);
     set_wc(20);
    set_ac(20);
    add_money(1000000);
    set_move_at_reset();
    set_long(
      "A happy little toe dancing around the big toe\n");
}
