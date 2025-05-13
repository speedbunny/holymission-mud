inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if(!arg) {

	set_name("feathers");
	set_short("A handfull of blue feathers");
	set_long("A handfull of dark blue feathers, perfectly plucked from a bluebird\n");
	set_weight(1);
	set_value(60);
	}
}