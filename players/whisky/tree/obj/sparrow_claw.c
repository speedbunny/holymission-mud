inherit "obj/weapon";

  reset(arg) {
  if (arg) return;

  set_id("sparrow claw");
   set_alias("claw");
  set_short("A sparrow claw");
  set_long("The weapon of the sparrow.\n");
  set_type(2);
  set_class(4);
  set_value(30);
   set_weight(1);

  } 

/* This is a non_metal weapon */

query_non_metal() {
  return 1;
}
