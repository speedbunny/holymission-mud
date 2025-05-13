	inherit "obj/weapon";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("ladle");
	set_class(3);
	set_type(2);
	set_weight(1);
	set_value(20);
	set_short("A ladle");
	set_long("Cooker's big ladle.\n");
}
