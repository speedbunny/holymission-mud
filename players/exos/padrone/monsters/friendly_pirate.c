inherit "obj/monster";

void reset(int flag) {
    ::reset(flag);
    if(flag) return;
    set_name("friendly pirate");
    set_alias("pirate");
    set_level(1);
    set_male();
    set_al(150);
    set_short("A friendly pirate");
    set_long("This is a small, friendly pirate.\n" +
      "He looks much nicer than the other pirates you have seen,\n" +
      "and probably the other pirates have locked him away in the vault\n" +
      "because they couldn't stand his friendly appearance.\n");
    set_aggressive(0);
    add_money(2+random(20));
}
