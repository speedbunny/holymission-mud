inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("firedrake");
    set_alias("drake");
    set_long("Its eyes glow red and vapours curl out of its nostrils.\n");
    set_level(30);
    set_al(-500);
    set_ac(20);
    set_wc(16);
    set_aggressive(1);
    set_chance(20);
    set_spell_mess1("Flames shoot from the firedrake's mouth!");
    set_spell_mess2("You are engulfed in flames!");
    set_spell_dam(45);
    add_money(765);
}
