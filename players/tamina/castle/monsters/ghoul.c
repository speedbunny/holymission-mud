inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if(arg) return;

	set_name("ghoul");
	set_level(17);
	set_short("A Ghoul");
	set_long("A wispy spectre, which wails and moans at you\n");
	set_al(-500);
	set_aggressive(1);
	set_hp(850);
	set_wc(17);
	set_ac(12);
	set_spell_mess2("The Ghoul wraps it freezing arms around your head.\n");
	set_spell_mess1("The Ghoul gives its victim a nice hug!!\n");
	set_chance(6);
	set_spell_dam(25+random(25));
	load_a_chat(17,
     ({"The Ghoul wails at you!\n",
       "The Ghoul sings a lament for his dead comrades.\n"}) );	

}
