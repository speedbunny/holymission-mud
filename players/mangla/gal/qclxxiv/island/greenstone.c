inherit "/obj/treasure";
ishort() { return "A very large, rather weird, green stone"; }
get() { write("It is way too heavy.. "); return 0; }
reset(arg) {
	if (arg) return;
	set_id("stone");
	set_alias("green stone");
	set_weight(10000);
   	set_short(0);
   	set_long(
"A very large, rather weird, massive and solid looking green stone.\n");
}
