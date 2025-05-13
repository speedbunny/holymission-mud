inherit "/obj/armour";

reset(arg){
	::reset(arg);
	if(arg) return 1;
	set_name("ghoul cloak");
	set_type("cloak");
	set_ac(0);
	set_weight(1);
	set_short("Ghoul's cloak");
	set_alias("cloak");
	set_long("This is a ragged cloak that looks like it once might have been worth\n" +"something.  Now it is so torn it can only belong to a ghoul.\n");
	set_value(30);
		return 1;
}
