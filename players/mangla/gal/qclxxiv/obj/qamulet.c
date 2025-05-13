inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qamulet");
		set_alias("qamulet");
		set_type("amulet");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(125);
		set_short("A not yet customized Qamulet");
		update_long();
		main_name = "amulet";
	}
}

id(str) { return (str=="amulet" || ::id(str)); }

update_long() {
	set_long(
"An uncustomized customizable Qamulet. For info type: help qamulet.\n"
+"This seems to be a "+desc_power()+" "+query_type()+
									". It does look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/* add_action("name_qamulet", "name_qamulet" ); */
	add_action("pref_qamulet", "pref_qamulet" );
	add_action("suf_qamulet", "suf_qamulet" );
	add_action("wpref_qamulet", "wpref_qamulet" );
	add_action("wsuf_qamulet", "wsuf_qamulet" );
}

help(str) {
	if (!str) return 0;
	if (str=="qamulet") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qamulet <some prefix>'\n"
+"or 'suf_qamulet <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qamulet' and 'wsuf_qamulet'.\n"
+"EXAMPLES: to make a: 'frost-amulet with purple star', issue commands:\n"
+"'wpref_qamulet frost-', and 'suf_qamulet with purple star'. \n"
+"Of course Qamulets can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black stone amulet', use: \n"
+"'pref_qamulet black stone'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qamulet(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qamulet(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qamulet(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qamulet(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qamulet(str) {
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
"One of those amazing customizable Qamulets. For info type: help qamulet.\n"
+"This seems to be a "+desc_power()+" amulet. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}
