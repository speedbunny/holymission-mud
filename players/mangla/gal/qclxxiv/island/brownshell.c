inherit "/obj/treasure";
reset(arg) {
	if (arg) return;
	set_id("shell");
	set_alias("brown shell");
	set_weight(1);
	set_value(20);
   	set_short("A brown shell");
   	set_long("A brown shell. Yet another cockleshell\n");
}

