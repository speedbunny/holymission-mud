inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("tail");
		set_alias("skunk tail");
		set_class(14);
		set_short("Skunk tail");
		set_long(
"The special stench spraying weapon of a skunk. In fights every now and then\n"
+"it will spray your enemy with a sickening stench, when wielded, making the\n"
+"enemy loose some extra health, as well as making him 'stinking'.\n"
+"You can also make someone 'stinking' without having a fight by using the\n"
+"command: spray someone. Have fun!\n"
);
		set_value(500);
		set_weight(2);
		set_hit_func(this_object());
	}
}

init() {
	::init();
	add_action("spray", "spray");
}

weapon_hit(ob)
{
	if (random(100)>70) {
		write( "You spray a sickening skunk stench towards your enemy.\n");
		tell_object(ob,"You are sprayed with a sickening skunk stench.\n" );	
		command( "puke", ob );
		ob->set_alignment("stinking");
		return 10;
	}
	return 0;
}

spray(str) {
    string who;
	object ob;
	if (!environment(this_object())==this_player()) return 0;
	if (!str) {
		write("spray whom?\n");
		return 1;
	}
    if (sscanf(str, "%s", who) == 1) 
	{
		ob = present( who, environment(this_player()));
		if (ob) {
			write( "You spray a sickening skunk stench towards your enemy.\n");
			tell_object(ob,"You are sprayed with a sickening skunk stench.\n");	
			command( "puke", ob );
			ob->set_alignment("stinking");
		}
		else write(str+" is not here.\n");
		return 1;
    }
	return 0;
}
