inherit "/obj/monster";

reset(arg) {
::reset();
  if (arg) return ;
  set_short("Phychor, the unholy");
set_name("Phychor");
  set_alias("phychor");
set_long("This is An old and imfamous Pharoh of ancient times.\n"+
"He looks very well preserved for being 5000 years old.\n");
  set_level(30);
  set_al(-100);
  set_hp(1800);
  set_wc(40);
  set_ac(10);
  set_spell_mess1("");
  set_spell_mess2("");
  set_chance(20);
  set_spell_dam(40);
  set_aggressive(0);
  add_money(3000);
move_object(clone_object("players/warlord/pyramid/scroll"),this_object());
}
