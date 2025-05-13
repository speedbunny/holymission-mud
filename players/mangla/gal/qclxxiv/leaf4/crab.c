#include "/players/qclxxiv/mymonster.h"
object loot1;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("crab");
	set_alias("wadden crab");
	set_race("crab");
	set_level(20);
   	set_wc(20);
	set_ac(20);
   	set_hp(1002);
	set_sp(100);
   	set_spell_mess1(
	"Crab grabs its attacker's right leg with its left scissored claw.");
   	set_spell_mess2(
	"Crab grabs your left leg with its right scissored claw.");
	set_chance(20);
	set_spell_dam(25);
	set_al(0);
   	set_aggressive(1);
   	set_short("A giant Wadden crab");
   	set_long(
	"A giant Wadden crab. Its scissors look sharp and its shield tough.\n"
	+"The shield could be a nice combat shield you figure.\n" );
	set_size(5);
}

second_life() {
	if (!loot1) {
		say(
"Crab's shield loosens from its body. Its scissors shiver for the last time\n");
		PLACE_IN_THIS(loot1,HOME+"leaf4/crabshield");
	}
	return 0;
}

