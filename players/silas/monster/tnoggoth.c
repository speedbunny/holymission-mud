inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("tnoggoth");
  set_alias("shark");
  set_short("Tnoggoth, the mutant shark");
  set_long("This creature is an immensely huge shark which likes to eat adventurers such\nas you for lunch. It is extremely dangerous and should not be messed with\nunless you have a death wish.\n");
  set_level(18);
  set_al(-500);
  set_hp(3000);
  add_money(2500+random(1000));
  set_wc(20);
  set_ac(3);
  set_chance(20);
  set_spell_dam(60);
  set_spell_mess1("Your bones crack as Tnoggoth takes a hefty bite into your torso.");
  set_spell_mess2("Most of your organs are permanently damaged after Tnoggoth chews you.");
  set_aggressive(1);
  move_object(clone_object("players/silas/obj/tnweapon"),
  this_object());
  init_command("wield teeth");
  move_object(clone_object("players/silas/obj/tnarmor"),
  this_object());
  init_command("wear skin");
  return 1;
}


