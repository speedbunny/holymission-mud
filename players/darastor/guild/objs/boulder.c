
inherit "obj/treasure";

reset(arg) {
  ::reset();

	set_short("A Large Boulder");
	set_name("boulder");
	set_long("A large boulder, it looks very heavy.\n");
	set_weight(20+random(10));
	set_value(1);
}
