	inherit"obj/food";
	
	reset(arg) {
	if(arg) return;

	set_name("salmon extract");
	set_short("A salmon's extract");
	set_alias("extract");
	set_long("Little piece of salmon's extract. It appears tasteful.\n");
	set_weight(2);
	set_value(130);
	set_eater_mess("Chomp Chomp ...\n");
	set_strength(10);
}
