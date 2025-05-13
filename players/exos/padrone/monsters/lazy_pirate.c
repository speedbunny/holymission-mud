inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("lazy pirate");
    set_alias("pirate");
    set_level(3);
    set_gender(1);
    set_hp(150);
    set_al(-100);
    set_short("A lazy pirate");
    set_long("This pirate looks very lazy.\n" +
      "He has sneaked away here to take a nap in the nice bed,\n" +
      "while his comrades are busy working at demolishing the castle.\n");
    set_aggressive(1);
    add_money(10+random(100));
}
