#include "/players/qclxxiv/mymonster.h"
object weapon;
reset(arg) {
	::reset(arg);
	if (!weapon) { PLACE_IN_THIS(weapon,HOME+"leaf6/basweapon"); }
	if (arg) return;
	load_chat(20,({ 
"Baneful basilisk clicks its jaws together.\n",
"Baneful basilisk roars: rrrrooooooaaaaarrrrrrrr.\n",
"Baneful basilisk roars: rrooooaaarrrrr.\n",
"Baneful basilisk glares at you with unhidden disgust.\n",
	}));
	load_a_chat(20,({ 
"Baneful basilisk tries to bite you.\n",
"Baneful basilisk roars: RRRROOOOOOAAAAARRRRRRRR.\n",
"Baneful basilisk glares at you with unhidden disgust.\n",
"Baneful basilisk roars: RROOOOAAARRRRR.\n",
"Baneful basilisk clicks its jaws together.\n",
"Baneful basilisk tries to grab your legs.\n",
	}));
	set_name("basilisk");
	set_alias("baneful basilisk");
	set_race("skum");
	set_level(35);
   	set_wc(37);
	set_ac(17);
   	set_hp(2900);
	set_sp(140);
   	set_spell_mess1(
		"Baneful basilisk hits its opponent BADLY.");
   	set_spell_mess2( 
		"Baneful basilisk hits you BADLY. It nearly broke your neck.");
	set_chance(40);
	set_spell_dam(85);
	set_al(-36);
   	set_aggressive(1);
   	set_short("Baneful basilisk");
	set_gender(0);
   	set_long(
"The baneful basilisk. It looks real real bad. The baleful and banefule\n"+
"bastard could attack you any moment, if it hasn't yet. Be careful!\n" );
	set_size(5);
}

