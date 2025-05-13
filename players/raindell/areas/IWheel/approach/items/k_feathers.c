inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if(!arg) {

	set_name("feathers");
	set_short("A handfull of red and grey feathers");
	set_long("A handfull of red and grey feathers, perfectly plucked from a kestral.\n");
	set_weight(1);
	set_value(150);
	}
}