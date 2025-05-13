inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
  if (!arg) {
	set_id("cudgel");
	set_class(10); 
	set_weight(1);
	set_value(300);
	set_short("An eelworm cudgel");
	set_long("An eelworm cudgel, used by root workers to cudgel eelworms.\n");
  }
}
