
inherit "obj/treasure";

reset(arg) {
  ::reset();
	
	set_short("A big rock");
	set_name("rock");
	set_long("A big rock, looks rather hard.\n");
	set_weight(10+random(10));
	set_value(1);
}
