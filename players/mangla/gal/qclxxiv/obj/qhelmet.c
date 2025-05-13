inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qhelmet");
		set_alias("qhelmet");
		set_type("helmet");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(75);
		set_short("A not yet customized Qhelmet");
		update_long();
		main_name = "helmet";
	}
}

update_long() {
	set_long(
"An uncustomized customizable Qhelmet. For info type: help qhelmet.\n"
+"This seems to be a "+desc_power()+" "+query_type()+
									". It does look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/*add_action("name_qhelmet", "name_qhelmet" );*/
	add_action("pref_qhelmet", "pref_qhelmet" );
	add_action("suf_qhelmet", "suf_qhelmet" );
	add_action("wpref_qhelmet", "wpref_qhelmet" );
	add_action("wsuf_qhelmet", "wsuf_qhelmet" );
}

help(str) {
	if (!str) return 0;
	if (str=="qhelmet") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qhelmet <some prefix>'\n"
+"or 'suf_qhelmet <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qhelmet' and 'wsuf_qhelmet'.\n"
+"EXAMPLES: to make a: 'frost-helmet with blue cross', issue commands:\n"
+"'wpref_qhelmet frost-', and 'suf_qhelmet with blue cross'. \n"
+"Of course Qhelmets can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black steel helmet', use: \n"
+"'pref_qhelmet black steel'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qhelmet(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qhelmet(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qhelmet(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qhelmet(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qhelmet(str) {
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
"One of those amazing customizable Qhelmets. For info type: help qhelmet.\n"
+"This seems to be a "+desc_power()+" helmet. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}
