inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qboots");
		set_alias("qboots");
		set_type("boot");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(50);
		set_short("Not yet customized Qboots");
		update_long();
		main_name = "boots";
	}
}

id(str) { return (str=="boots" || ::id(str)); }

update_long() {
	set_long(
"Uncustomized customizable Qboots. For info type: help qboots.\n"
+"They seem to be "+desc_power()+" "+query_type()+
									"s. They do look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/* add_action("name_qboots", "name_qboots" ); */
	add_action("pref_qboots", "pref_qboots" );
	add_action("suf_qboots", "suf_qboots" );
	add_action("wpref_qboots", "wpref_qboots" );
	add_action("wsuf_qboots", "wsuf_qboots" );
}

help(str) {
	if (!str) return 0;
	if (str=="qboots") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qboots <some prefix>'\n"
+"or 'suf_qboots <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qboots' and 'wsuf_qboots'.\n"
+"EXAMPLES: to make a: 'frost-boots with blue cross', issue commands:\n"
+"'wpref_qboots frost-', and 'suf_qboots with blue cross'. \n"
+"Of course Qboots can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black steel boots', use: \n"
+"'pref_qboots black steel'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qboots(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qboots(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qboots(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qboots(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qboots(str) {
	if (!str) return 0;
	suf_name = str;
	return update();
}

update() {
	set_name(main_name);
	if (pref_name) cur_name = pref_name + main_name;
	else cur_name = main_name;
	if (suf_name) cur_name += suf_name;
	set_short(cur_name);
	set_long(cur_name+".\n"+
"A pair of those amazing customizable Qboots. For info type: help qboots.\n"
+"They seem to be "+desc_power()+" boots. They do look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}

