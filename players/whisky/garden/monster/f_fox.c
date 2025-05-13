inherit "obj/monster";

reset (arg) {
  ::reset(arg);

  if (!arg) {

  set_name("father fox");
  set_alt_name("fox");
  set_short("The father fox");
  set_long("He looks very angry.\n");
  set_level(3);
  set_size(2);
  set_aggressive(1);
  set_spell_mess1("The father  fox bites you in your leg");
  set_spell_mess2("The father fox hits you with it's claw");
  set_chance(80);
  set_spell_dam(2);
  move_object(clone_object("players/whisky/garden/obj/fox_jacket2"),
  this_object());
}
}
