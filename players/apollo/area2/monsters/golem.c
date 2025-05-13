
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("stone golem");
  set_alias("golem");
  set_short("stone golem");
  set_long("This creature has come alive. He bears a striking \n" +
	   "resemblance towards the mountain cliffs around around \n" +
	   "you making you think that he will be as hard as stone. \n");
  set_level(15);
  set_al(-250);
  set_hp(900);
  set_wc(15);
  set_ac(8);
  set_chance(33);
  set_spell_dam(40);
  set_spell_mess1("The golem smashes its fist upon your head.");
  set_spell_mess2("The golem knocks the wind out of your lungs \n" +
		  "with a swift punch.");
  set_aggressive(1);

  move_object(clone_object("players/apollo/area2/weapons/sarundot"),
  	this_object());
  init_command("wield sarundot");

  move_object(clone_object("players/apollo/area2/obj/diamond"),
  	this_object());

}

monster_died(ob) {
  this_player()->add_exp(1250);
  return 0;
}
