inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("sword");
		set_alias("skumsword");
		set_class(18);
		set_short("Skumsword");
		set_long("A skumsword, especially good to kill skum with.\n"+
		"It's amazing to realize it was carried by a piece of skum before!\n" );
		set_value(1000);
		set_weight(3);
		set_hit_func(this_object());
	}
}

weapon_hit(ob)
{
	if (ob->query_alignment()<-40 || ob->query_race()=="skum") {
		if (random(100)>80) {	
			write( 
				"Your skumsword chooses it's own way and HITS the skum!!!\n");
			tell_object(ob,
					"The skumsword of your enemy HITS you violently!!!\n");	
			return 40;
		}
	}
	if (ob->query_alignment()<-10 ) {
		if (random(100)>85) {	
			write( 
			"You're skumsword chooses it's own way and hits the skum!!!\n");
			tell_object(ob,
					"The skumsword of your enemy hits you violently!!!\n");	
			return 27;
		}
	}
	return 0;
}

