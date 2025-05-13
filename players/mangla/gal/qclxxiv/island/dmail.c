inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("mail");
		set_alias("dragon fighters mail");
		set_ac(3);
/*		set_type("mail"); */
		set_short("Dragon Fighters Mail");
		set_long(
"The Dragon Fighters Mail. A heavy and strong piece of craftmanship, with a\n"
+"magic vibration about it.\n");
		set_value(500);
		set_weight(3);
	}
}
id(arg) { return (::id(arg) || arg=="qdragonmail"); }

query_quest_item() { return 1; }
query_dragonmail() { return 1; }

armour_class() {
	if (environment() && environment()->query_guild()==5) return 0;
	return ac;
}

query_monk_wear() {
	return 1;
}
