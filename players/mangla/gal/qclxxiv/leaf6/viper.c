#include "/players/qclxxiv/mymonster.h"
object teeth;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ "ssssssslllssss\n", "sssssslllss\n", }));
	load_a_chat(10,({ "SSSSSLLLLLSLSSSS\n", "SSSLSSSS\n", }));
	set_name("viper");
	set_alias("snake");
	set_race("skum");
	set_level(12);
   	set_wc(11);
	set_ac(4);
   	set_hp(426);
	set_sp(140);
   	set_spell_mess1(
		"The viper clutches its poison teeth deep into its opponent.");
   	set_spell_mess2("The viper clutches its poison teeth deep into you.");
	set_chance(20);
	set_spell_dam(10);
	set_al(-5);
   	set_aggressive(0);
   	set_short("A viper");
   	set_long("A poisonous viper, ready to bite you.\n");
	set_size(3);
	PLACE_IN_THIS(teeth,HOME+"leaf6/viperteeth");
	init_command("wield teeth");
}

