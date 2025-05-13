inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shadow lurker");
  set_short("Shadow lurker");
  set_long("A small, hideous-looking beast misshapen into a hunched and\n" +
	   "gnarled form, the Lurker blends in nearly perfectly with its\n" +
	   "dark surroundings.\n");
  set_race("lurker");
  set_level(12);
  set_hp(250);
  set_wc(10);
  set_ac(10);
  set_aggressive(1);
  set_chance(80);
  set_spell_mess1("The Lurker throws back its head and SCREAMS!");
  set_spell_mess2("Your ears nearly shatter as the Lurker SCREAMS!");
  set_spell_dam(40);
  add_money(500);
}
