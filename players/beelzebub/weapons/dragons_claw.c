
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("Dragon's Claw");
  set_alias("claw");
  set_class(11);
  set_short("A Dragon's Claw");
  set_long("A very long and very sharp dragon's claw. \n");
  set_value(1500);
  set_weight(2);
  return 1;
}

