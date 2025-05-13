inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("parry dagger");
    set_alias("dagger");
    set_alt_name("parrydagger");
    set_class(5);
    set_weight(1);
    set_value(2500);
    set_short("A parry dagger");
    set_long("This is a rather inconspicuous dagger, but with a simple\n"+
      "twist of its pummel, the blade splits into a W shape.  Making it\n"+
      "easier to parry and/or break weapons.\n");
}

wield(str) {
    object parry;

    if(environment(this_object())!=this_player()) {
	write("You do not have the dagger!\n");
	return 1;
    }
    if(str=="dagger" || str=="parry" || str=="parrydagger") {
	if(!this_player()->parry_shad()) {
	    parry = clone_object("/players/exos/objects/parry_shad");
	    parry->start_shadow(this_player(),100000,"parry_shad");
	    write("Shadow starting.\n");
	}
	return ::wield(str);
    }
    return 0;
}

do_unwield(str) {
    if(str=="dagger" || str=="parry" || str=="parrydagger") {
	if(this_player()->parry_shad()) {
	    this_player()->end_shadow(this_player());
	    write("Shadow ending.\n");
	}
	return ::do_unwield(str);
    }
    return 0;
}

drop(str) {
    if(wielded) {
	if(this_player()->parry_shad()) {
	    this_player()->end_shadow(this_player());
	    write("Shadow ending.\n");
	}
	wielded=0;
	tell_object(wielded_by,"You drop your wielded weapon.\n");
	wielded_by=0;
    }
    return 0;
}
