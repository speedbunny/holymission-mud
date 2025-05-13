#include "/players/qclxxiv/mymonster.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("fish");
	set_alias("jelly fish");
	set_race("jelly-fish");
	set_level(20);
   	set_wc(20);
	set_ac(20);
   	set_hp(1100);
	set_sp(100);
   	set_spell_mess1(
	"Jelly-fish strikes its attacker with its poison tentacles.");
   	set_spell_mess2(
	"Jelly-fish strikes you with its poison tentacles.");
	set_chance(17);
	set_spell_dam(30);
	set_al(-5);
   	set_aggressive(1);
   	set_short("A giant jelly-fish");
   	set_long(
	"A giant jelly-fish. Its poison tentacles and body are purple spotted.\n");
	set_size(5);
}
