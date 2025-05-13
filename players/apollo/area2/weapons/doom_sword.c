
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("sword");
  set_alias("doom sword");
  set_class(20);
  set_short("doom sword");
  set_long("This is the sword of the stone golem. From the looks \n" +
	   "of it this weapon must have been crafted by an experienced \n" +
	   "smith. The steel blade shimmers strangely and you feel that \n" +
	   "this must be a weapon worthy of its bearer. \n");
  set_value(3500);
  set_weight(4);
  return 1;
}

