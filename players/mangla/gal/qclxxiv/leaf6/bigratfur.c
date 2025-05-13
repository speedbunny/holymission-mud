inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("fur");
		set_ac(2);
		set_short("A grubby rat fur");
		set_value(90);
		set_weight(1);
	}
}
