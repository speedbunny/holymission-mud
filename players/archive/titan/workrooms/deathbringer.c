inherit "obj/weapon";

reset(arg) {
if (arg) return;

   set_name("Titan's deathbringer");
   set_id("deathbringer");
   set_short("Titan's deathbringer");
   set_alt_name("bringer");
   set_alias("bringer");
   set_long("Very strange kind of weapon. It is dark but when you are killing it\n"
	    "beams blue light.\n");
   set_light(10);
   set_value(5000);
   set_weight(1);
   set_type(3);
   set_hit_func(this_object());
}
weapon_hit(attacker) {
	write("You cut"+attacker->query_name()+" with brutal force.\n"
	+ "Deathbringer beams blue light.\n");
	say("You see that Commodore Titan cuts "+attacker->query_name()+" and parts of body flies to all directions.\n");
	return 19000;
}
