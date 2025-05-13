inherit "obj/armour";
object taking, followed;
string main_name, pref_name, suf_name, cur_name;
string power_desc, weight_desc;
customID() { return 1; }

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_descriptions();
		set_name("follow ring");
		set_alias("ring");
		set_type("ring");
		::set_ac(1);
		set_size(0);
		::set_weight(1);
		set_value(200);
		set_short("A ring of following");
		update_long();
		main_name = "ring";
	}
}
set_weight( i ) { ::set_weight(i); update_long(); }

set_ac( i ) { ::set_ac(i); update_long(); }

update_long() {
	set_long( "A ring of following. Type: ringfollow somename  to follow\n"
+"someone named sonename.\n");
}

set_descriptions() {
	power_desc = ({ "modest", "normal", "good", "very good", "excellent", });

	weight_desc = ({ "very light", "rather light", "not too heavy",
					"not too light", "heavy", "very heavy",
					"extremely heavy", });
}

desc_power() {
	int i;
	i = armour_class();
	if (i>=sizeof(power_desc)) i = sizeof(power_desc)-1;
	if (query_type()=="armour") 
		return power_desc[i];
	else return  i? "very good" : "modest";
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
	add_action("unwear", "unwear");
	/*add_action("name_qring", "name_qring" );*/
	add_action("pref_qring", "pref_qring" );
	add_action("suf_qring", "suf_qring" );
	add_action("wpref_qring", "wpref_qring" );
	add_action("wsuf_qring", "wsuf_qring" );
	add_action("follow", "ringfollow" );
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
+"main type name use special forms: 'wpref_qring' and 'wsuf_ring'.\n"
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

unwear(str) {
	if (!str) {
		write("Unwear what?\n");
		return 1;
	}
	if (!id(str)) return 0;
	if (worn) {
		this_player()->stop_wearing(this_object());
		worn = 0;
		return 1;
	}
	return 0;
}

follow(str) {
	if (!str) write("Follow whom?\n");
	else if (environment(this_object())==this_player() && query_worn()) {
		if (find_living(str)) {
			followed = find_living(str);
			taking = this_player();
			call_out("heart_beat",2);
		}
		else write("Cant find any living named: "+str+"\n");
	}
	return 1;
}

heart_beat() {
	if (taking && followed && query_worn()) {
		if (environment(this_object())==taking) {
			if (environment(taking)!=environment(followed)
				&& environment(taking) && environment(followed))
				taking->move_player("to a friend", environment(followed));
			call_out("heart_beat", 2);
		}
	}
}

