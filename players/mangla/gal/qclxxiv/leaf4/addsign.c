inherit "/obj/treasure";

reset(arg) {
	if (arg) return;
	set_id("sign");
	set_short("A sign");
	set_long("A sign, mounted firmly on a solidly grounded pole.\n");
	set_read("You have been warned... Turn south!\n");
}

get() { return 0; }
