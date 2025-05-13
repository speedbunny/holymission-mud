inherit "obj/weapon";

string main_name, pref_name, suf_name, cur_name;
string power_desc, weight_desc;
customID() { return 1; }

reset(arg) {
	::reset(arg);
	if (!arg) {
		main_name = "qweapon";
		set_descriptions();
		set_name("qweapon");
		set_alias("qweapon");
		::set_class(15);
		::set_weight(3);
		set_value(700);
		set_short("A not yet customized Qweapon");
		update_long();
	}
}

id(str) { return (str=="weapon" || ::id(str)); }
set_weight( i ) { ::set_weight(i); update_long(); }

set_class( i ) { ::set_class(i); update_long(); }

update_long() {
	set_long(
"An uncustomized customizable Qweapon. For info type: help qweapon.\n"
+"This seems to be a "+desc_power()+" weapon. It does look "+desc_weight()+".\n"
			);
}

set_descriptions() {
				/*   0-4    5-8      9-11           12-14       15-19 */
	power_desc = ({ 
					"worthless", "nice", "nice", "nice", "nice", 
					"good", "good", "good", "good", 
					"pretty good", "pretty good", "pretty good", 
					"powerful", "powerful", "powerful", 
					"very powerful", "very powerful", "very powerful",
					"very powerful", "very powerful",
					"extremely powerful", });
	weight_desc = ({ "very light", "rather light", "not too heavy",
					"not too light", "heavy", "very heavy",
					"extremely heavy", });
}

desc_power() {
	int i;
	i = weapon_class();
	if (i>=sizeof(power_desc)) i = sizeof(power_desc)-1;
	return power_desc[i];
}

desc_weight() {
	int i;
	i = query_weight();
	if (i>=sizeof(weight_desc)) i = sizeof(weight_desc)-1;
	return weight_desc[i];
}

init() {
	::init();
	add_action("help", "help");
	add_action("unwield", "unwield");
	/* add_action("name_qweapon", "name_qweapon" ); */
	add_action("pref_qweapon", "pref_qweapon" );
	add_action("suf_qweapon", "suf_qweapon" );
	add_action("wpref_qweapon", "wpref_qweapon" );
	add_action("wsuf_qweapon", "wsuf_qweapon" );
}

help(str) {
	if (!str) return 0;
	if (str=="qweapon") {
		write(
"A prefix and a suffix can be given using resp. 'pref_qweapon <some prefix>'\n"
+"or 'suf_qweapon <some suffix>'. The prefix and suffix can be freely set.\n"
			);
		write(
"Take care: to allow prefix and suffix to be added without a space to the\n"
+"main type name use special forms: 'wpref_qweapon' and 'wsuf_qweapon'.\n"
+"EXAMPLES: to make a: 'battleaxe with rusty blade', issue commands:\n"
+"'wpref_qweapon battle', and 'suf_qweapon with rusty blade'. \n"
			);
		write( "For a: 'black steel sword', use: \n"
+"'pref_qweapon black steel'.    You can change all as oft as you like.\n"
+"Of course Qweapons can not only be wielded, but also unwielded.\n"
		    );
		return 1;
	}
	return 0;
}

name_qweapon(str) {
	if (!str) return 0;
	main_name = str;
	return update();
}

pref_qweapon(str) {
	if (!str) return 0;
	pref_name = str + " ";
	return update();
}

suf_qweapon(str) {
	if (!str) return 0;
	suf_name = " " + str;
	return update();
}

wpref_qweapon(str) {
	if (!str) return 0;
	pref_name = str;
	return update();
}

wsuf_qweapon(str) {
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
"One of those amazing customizable Qweapons. For info type: help qweapon.\n"
+"This seems to be a "+desc_power()+" weapon. It does look "+desc_weight()+".\n"
	);
	write("Ok.\n");
	return 1;
}

unwield(str) {
	if (wielded) {
		if (!this_player()->stop_wielding()) return 1;
		wielded = 0;
		write("Ok.\n");
		return 1;
	}
	return 0;
}
