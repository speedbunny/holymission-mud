inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("vampire");
    set_race("vampire");
    set_long("You cannot look directly at the vampire!\n");
    set_level(40);
    set_al(-500);
    set_ac(14);
    set_wc(14);
    set_aggressive(1);
    set_chance(20);
    set_spell_mess1("The vampire drinks deeply of its victim's blood.");
    set_spell_mess2("The vampire drinks your blood, draining your strength.");
    set_spell_dam(60);
    add_money(578);
}
