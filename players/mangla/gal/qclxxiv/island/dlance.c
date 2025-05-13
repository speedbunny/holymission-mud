inherit "obj/weapon";
string owner;
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("lance");
		set_alias("dragon lance");
		set_class(14);
		set_short("Dragon Slaughterers Lance");
		set_long("The Dragon Slaughterers Lance. It looks long, strong, and heavy.\n");
		set_value(1000);
		set_weight(4);
		set_hit_func(this_object());
	}
}

query_quest_item() { return 1; }
set_owner(arg) { owner = arg; }

id(arg) { return (::id(arg) || arg=="Dragon Slaughters Lance" || arg=="Lance");}

weapon_hit(ob)
{
	if (this_player()->query_real_name()!=owner) return 0;
	if (ob->id("island dragon")) {
		if (random(100)>10) {	
			write( 
"The Dragon Slaughterers Lance chooses its own way into the dragon's\n"
+"weakest spot!!!\n");
			tell_object(ob,
					"The Dragon Slaughterers Lance struck you awfully!!!\n");	
			return 10000;	/* still the only way to kill poisoned dragon */
		}
	}
	if (ob->id("dragon")) {
		if (random(100)>75) {	
			write( 
"The Dragon Slaughterers Lance chooses its own way into the dragon!!!\n");
			tell_object(ob,
					"The Dragon Slaughterers Lance struck you badly!!!\n");	
			return 40;	
		}
	}
	return 0;
}

wield(str) {
	if (id(str) && ::wield(str)) {
		if ( wielded && wielded_by==this_player()) {
			if (this_player()->query_real_name()!=owner)
				write(
"You suddenly get the feeling that this is not the real Dragon Slaughters\n"
+"Lance after all!!!....\n");
		}
		return 1;
	}
	return 0;
}
