inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("sorceror");
  set_short("Konji the Sorceror");
  set_alias("konji");
set_long("He is very powerful so take warning.\n");
  set_level(25);
   add_money(1500);
  set_spell_dam(70);
  set_al(-200);
  return 1;
  }
