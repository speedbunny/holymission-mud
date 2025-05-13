inherit "obj/monster";


reset(arg) {
  ::reset(arg);
  if (arg) return;
    set_name("wind elemental");
    set_alias("elemental");
    set_race("elemental");
    set_long("The wind elemental is hard to look at exactly.  But you get\n" +
             "a sensation of a great wind contained in a small form.\n");
    set_level(27);
    set_ac(23);
    set_wc(27);
    set_al(-500);
    set_chance(30);
    set_spell_mess1("The elemental forms itself into a tornado!");
    set_spell_mess2("The elemental sucks you up into a tornado!");
    set_spell_dam(55);
    set_aggressive(0);
    add_money(1100);

}
