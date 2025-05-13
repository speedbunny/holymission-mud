inherit "/obj/monster";
object club;

reset(arg) {
	::reset(arg);
	if(arg) return 1; 
	set_name("mulabi");
	set_short("Mulabi the Ogre");
	set_long("Mulabi is a mean and vicious witch.  She redefines the term UGLY!\n" + "She may be fat, but she's got her share of strength.\n");
	set_level(17);
	set_alias("ogre");
	set_al(-100);
	set_ac(7);
	set_hp(500);
	set_aggressive(1);
	add_money(100 *(random(10)+1));
   club=clone_object("players/airborne/weapons/fist");
   move_object(club,this_player());
   init_command("wield club");
	   return 1;
}
