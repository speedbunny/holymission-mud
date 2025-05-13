inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("greedy pirate");
    set_alias("pirate");
    set_level(5);
    set_male();
    set_hp(150);
    set_al(-100);
    set_short("A greedy pirate");
    set_long("This pirate looks very greedy.\n" +
      "He has stolen some money, and now he has sneaked away up here\n" +
      "so he won't have to share it with his comrades.\n");
    set_aggressive(1);
    add_money(100+random(300));
}
