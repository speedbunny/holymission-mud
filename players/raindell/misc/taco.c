inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if(!arg) {

	set_name("taco");
	set_short("A tasty looking taco");
	set_long("Amazing! The bluebird must have been munching on this before it died!");
	}
}