inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qcloak");
		set_alias("qcloak");
		set_type("cloak");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(100);
		set_short("A not yet customized Qcloak");
		update_long();
		main_name = "cloak";
	}
}

update_long() {
	set_long(
"An uncustomized customizable Qcloak. For info type: help qcloak.\n"
+"This seems to be a "+desc_power()+" "+query_type()+
									". It does look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/* add_action("name_qcloak", "name_qcloak" ); */
	add_action("pref_qcloak", "pref_qcloak" );
	add_action("suf_qcloak", "suf_qcloak" );
	add_action("wpref_qcloak", "wpref_qcloak" );
	add_action("wsuf_qcloak", "wsuf_qcloak" );
}

help(str) {
	if (!str) return 0;
	if (str=="qcloak") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qcloak <some prefix>'\n"
+"or 'suf_qcloak <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qcloak' and 'wsuf_qcloak'.\n"
+"EXAMPLES: to make a: 'war-cloak with mirrors, issue commands:\n"
+"'wpref_qcloak war-', and 'suf_qcloak with mirrors'. \n"
+"Of course Qcloaks can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'blue velvet cloak', use: \n"
+"'pref_qcloak blue velvet'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qcloak(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qcloak(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qcloak(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qcloak(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qcloak(str) {
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
"One of those amazing customizable Qcloaks. For info type: help qcloak.\n"
+"This seems to be a "+desc_power()+" cloak. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}

