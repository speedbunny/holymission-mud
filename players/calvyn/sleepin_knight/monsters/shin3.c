inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Shin Splint");
    set_short("Shin Splint");
    set_alias("shin");  
    set_gender(random(0));
    set_level(7);
    set_wc(6);
    set_ac(3);
    set_move_at_reset();
    set_long(
      "A shin splint stands in agony\n");
}
