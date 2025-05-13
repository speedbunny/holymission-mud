inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("azanar");
set_short("Azanar, Guardian of the tomb");
set_long("This is one of four identical guards of the tomb\n");
  set_level(20);
  set_wc(random(20));
  set_ac(10);
  set_al(200);
  set_spell_mess1("");
  set_spell_mess2("");
  set_chance(4);
  set_spell_dam(100);
  add_money(1500);
  set_aggressive(0);
  return 1;
}
