inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qshield");
		set_alias("qshield");
		set_type("shield");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(200);
		set_short("A not yet customized Qshield");
		update_long();
		main_name = "shield";
	}
}

update_long() {
	set_long(
"An uncustomized customizable Qshield. For info type: help qshield.\n"
+"This seems to be a "+desc_power()+" "+query_type()+
									". It does look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/*add_action("name_qshield", "name_qshield" );*/
	add_action("pref_qshield", "pref_qshield" );
	add_action("suf_qshield", "suf_qshield" );
	add_action("wpref_qshield", "wpref_qshield" );
	add_action("wsuf_qshield", "wsuf_qshield" );
}

help(str) {
	if (!str) return 0;
	if (str=="qshield") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qshield <some prefix>'\n"
+"or 'suf_qshield <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qshield' and 'wsuf_qshield'.\n"
+"EXAMPLES: to make a: 'frost-shield with blue cross', issue commands:\n"
+"'wpref_qshield frost-', and 'suf_qshield with blue cross'. \n"
+"Of course Qshields can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black steel shield', use: \n"
+"by: 'pref_qshield black steel'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qshield(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qshield(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qshield(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qshield(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qshield(str) {
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
"One of those amazing customizable Qshields. For info type: help qshield.\n"
+"This seems to be a "+desc_power()+" shield. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}
