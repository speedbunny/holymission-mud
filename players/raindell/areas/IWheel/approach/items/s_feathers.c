inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if(!arg) {

	set_name("feathers");
	set_short("A handfull of black feathers");
	set_long("A handfull of black feathers, perfectly plucked from a swallow.\n");
	set_weight(1);
	set_value(100);
	}
}