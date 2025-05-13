inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("sword");
  set_alias("sarundot");
  set_class(40);
  set_short("sarundot");
  set_long("This is the sword of the stone golem. From the looks of it this weapon must\nhave been crafted by an experienced smith. The steel blade shimmers strangely\nand you feel that this must be a weapon worthy of its bearer.\n");
  set_value(3500);
  set_weight(2);
  return 1;
}

