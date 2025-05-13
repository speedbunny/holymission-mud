inherit "obj/monster";


reset(arg) {
  ::reset(arg);
  if (arg) return;
    set_name("wight");
    set_alias("wight");
    set_race("wight");
    set_long("The wight feeds by draining its victims with its touch,\n" +
             "so beware!\n");
    set_level(45);
    set_ac(23);
    set_wc(27);
    set_al(-500);
    set_chance(30);
    set_spell_mess1("The wight reaches out with its finger.");
    set_spell_mess2("You feel your lifeforce drained away.");
    set_spell_dam(90);
    set_aggressive(1);
    add_money(1100);

}
