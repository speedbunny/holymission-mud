#include "/players/tamina/defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

	set_name("Darkling Concubine");
	set_alias("concubine");
	set_alt_name("darkling");
	set_race("darkling");
	set_gender(2);
	set_level(20);
	set_short("The beloved concubine of the Darkling Prince");
	set_long("A tall figure who simply exudes passionate charm.\n");
	set_al(-100);
	set_aggressive(0);
	set_size(3);
	set_hp(800);
	set_wc(25);
	set_ac(10);
	set_spell_mess1(" \n");
	set_spell_mess2(" \n");
	set_spell_dam(25+random(41));
	set_chance(7);
	add_money(1500);
}

