inherit "obj/weapon";
reset(arg) {
  ::reset(arg);
  if(arg) return 1;
  set_name("sun sword");
  set_alias("sword");
  set_short("Sun Sword");
  set_long("This is Omega's sun sword\n");
  set_weight(10);
  set_value(25000);
   set_class(30);
  return 1;
  }
