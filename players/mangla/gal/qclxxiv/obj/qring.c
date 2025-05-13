inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qring");
		set_alias("qring");
		set_type("ring");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(200);
		set_short("A not yet customized Qring");
		update_long();
		main_name = "ring";
	}
}

update_long() {
	set_long(
"An uncustomized customizable Qring. For info type: help qring.\n"
+"This seems to be a "+desc_power()+" "+query_type()+
									". It does look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/*add_action("name_qring", "name_qring" );*/
	add_action("pref_qring", "pref_qring" );
	add_action("suf_qring", "suf_qring" );
	add_action("wpref_qring", "wpref_qring" );
	add_action("wsuf_qring", "wsuf_qring" );
}

help(str) {
	if (!str) return 0;
	if (str=="qring") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qring <some prefix>'\n"
+"or 'suf_qring <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qring' and 'wsuf_qring'.\n"
+"EXAMPLES: to make a: 'seal-ring with red stone', issue commands:\n"
+"'wpref_qring seal-', and 'suf_qring with red stone'. \n"
+"Of course Qrings can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black steel ring', use: \n"
+"'pref_qring black steel'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qring(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qring(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qring(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qring(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qring(str) {
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
"One of those amazing customizable Qrings. For info type: help qring.\n"
+"This seems to be a "+desc_power()+" ring. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}
