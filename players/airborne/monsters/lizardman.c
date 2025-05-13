inherit "/obj/monster";
object spear;

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("lizardman");
	set_alias("man");
	set_short("Lizardman");
	set_long("A mean looking lizardman stares you in the eyes.\n");
	set_level(5);
	set_frog();
	set_al(0);
	set_aggressive(1);
   spear=clone_object("players/airborne/weapons/spear");
   move_object(spear,this_object());
   init_command("wield spear");
return 1;
}
