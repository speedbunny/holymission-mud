inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qgloves");
		set_alias("qgloves");
		set_type("glove");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(50);
		set_short("Not yet customized Qgloves");
		update_long();
		main_name = "gloves";
	}
}
id(str) { return (str=="gloves" || ::id(str)); }

update_long() {
	set_long(
"Uncustomized customizable Qgloves. For info type: help qgloves.\n"
+"They seem to be a "+desc_power()+" "+query_type()+
									"s. They do look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/*add_action("name_qgloves", "name_qgloves" );*/
	add_action("pref_qgloves", "pref_qgloves" );
	add_action("suf_qgloves", "suf_qgloves" );
	add_action("wpref_qgloves", "wpref_qgloves" );
	add_action("wsuf_qgloves", "wsuf_qgloves" );
}

help(str) {
	if (!str) return 0;
	if (str=="qgloves") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qgloves <some prefix>'\n"
+"or 'suf_qgloves <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qgloves' and 'wsuf_qgloves'.\n"
+"EXAMPLES: to make a: 'frost-gloves with blue cross', issue commands:\n"
+"'wpref_qgloves frost-', and 'suf_qgloves with blue cross'. \n"
+"Of course Qgloves can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black steel gloves', use: \n"
+"'pref_qgloves black steel'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qgloves(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qgloves(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qgloves(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qgloves(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qgloves(str) {
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
"A pair of those amazing customizable Qgloves. For info type: help qgloves.\n"
+"They seem to be "+desc_power()+" boots. They do look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}

