inherit "obj/weapon";

  reset(arg) {
   ::reset(arg);
 if (arg) return;

  set_name("spear");
  set_class(10);
  set_weight(1);
  set_value(200);
  set_alias("native spear");
  set_short("A native spear");
  set_long("The weapon of the natives from the vulcano island.\n");
  set_type(2);
}

