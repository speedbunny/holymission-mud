inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("sword");
		set_alias("sundawn");
		set_alt_name("q174_sundawn");
		set_class(18);  /* have to kill 9 very tough monsters for it */
		set_short("The sword Sundawn");
		set_long(
"The sword Sundawn. An old large sword, long and sharp. It shines weird\n"+
"and has a magic look about it. It is clearly dwarfen made. It somehow\n"
+"makes you think of giant eelworms being slaughtered and cut to pieces...\n"
		);
		set_value(2000);
		set_weight(4);
		set_hit_func(this_object());
	}
}

weapon_hit(ob)
{
	if (ob->query_npc() && random(100)>50) {
		write("Sundawn paralizes the worm.\n");
		ob->set_whimpy(0);
	}
	if (ob->query_race() == "eelworm" ) {
		if (random(100)>50) {	
			write( 
"Sundawn appears to come alive and BITES its way into the worm!!!!!. \n");
			return 2*environment()->query_level();
		}	/* eelworms give reduced ep....are tougher than player (always
			as they adapt to player!) and this sword has been obtained
			after many even harder fights.. after that the goal in the
			quest is that player can easily kill 30 eelworms   or they
			can ommit the 10 veryhard boxworms and do the 30  eelworms
			the hard way.   therefore ONLY for eelworms this sword is
			so strong */
	}
	return 0;
}

