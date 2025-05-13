inherit "obj/armour";

string main_name, pref_name, suf_name, cur_name;
string power_desc, weight_desc;
customID() { return 1; }

set_weight( i ) { ::set_weight(i); update_long(); }

set_ac( i ) { ::set_ac(i); update_long(); }

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
	add_action("unwear", "unwear");
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

query_monk_wear() {
	return (armour_class()<1 );
}

query_mage_wear() {
	return (armour_class()<1 );
}
