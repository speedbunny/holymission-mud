inherit "/players/qclxxiv/obj/qarmour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("qmail");
		set_alias("qmail");
		set_type("armour");
		::set_ac(2);
		set_size(0);
		::set_weight(2);
		set_value(75);
		set_short("A not yet customized Qmail");
		update_long();
		main_name = "mail";
	}
}
id(str) { return (str=="mail" || ::id(str)); }

update_long() {
	set_long(
"An uncustomized customizable Qmail. For info type: help qmail.\n"
+"This seems to be a "+desc_power()+" "+query_type()+
									". It does look "+desc_weight()+".\n"
			);
}

init() {
	::init();
	add_action("help", "help");
	/*add_action("name_qmail", "name_qmail" ); */
	add_action("pref_qmail", "pref_qmail" );
	add_action("suf_qmail", "suf_qmail" );
	add_action("wpref_qmail", "wpref_qmail" );
	add_action("wsuf_qmail", "wsuf_qmail" );
}

help(str) {
	if (!str) return 0;
	if (str=="qmail") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qmail <some prefix>'\n"
+"or 'suf_qmail <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qmail' and 'wsuf_qmail'.\n"
+"EXAMPLES: to make a: 'frost-mail with blue cross', issue commands:\n"
+"'wpref_qmail frost-', and 'suf_qmail with blue cross'. \n"
+"Of course Qmails can not only be worn, but also be put off by 'unwear'.\n"
			);
		write( "For a: 'black steel mail', use: \n"
+"'pref_qmail black steel'.    You can change all as oft as you like.\n"
		    );
		return 1;
	}
	return 0;
}

name_qmail(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qmail(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qmail(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qmail(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qmail(str) {
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
"One of those amazing customizable Qmails. For info type: help qmail.\n"
+"This seems to be a "+desc_power()+" mail. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}
