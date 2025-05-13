inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("green snake");
  set_alias("snake");
  set_race("snake");
  set_short("Small green snake");
  set_long("A lithe serpent slithering through the grass, this snake\n" +
	   "has a strange look about it; its eyes glow red with some\n" +
	   "unholy light.\n");
  set_level(8);
  set_hp(75);
  set_al(-150);
  set_wc(5);
  set_ac(5);
  add_money(50);
  set_chance(10);
  set_spell_dam(5);
  set_spell_mess1("The snake hisses and suddenly strikes!");
  set_spell_mess2("The snake rears up and strikes at you!");
  load_chat(1, ({ "Ssssssss ...\n" }));
}
