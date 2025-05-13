inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("teeth");
		set_alias("viper teeth");
		set_class(12);
		set_short("Viper teeth");
		set_long("The poison teeth of a viper.\n");
		set_value(200);
		set_weight(1);
	}
}
