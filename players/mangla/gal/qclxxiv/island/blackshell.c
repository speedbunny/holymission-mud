inherit "/obj/treasure";
reset(arg) {
	if (arg) return;
	set_id("shell");
	set_alias("black shell");
	set_weight(1);
	set_value(10);
   	set_short("A black shell");
   	set_long("A black shell. Yet another cockleshell\n");
}
