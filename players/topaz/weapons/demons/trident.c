inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("trident");
  set_short("A hot trident");
  set_long("This trident is VERY hot!  It would probably hurt a lot to\n" +
           "get hit with it.\n");
  set_class(10);
  set_value(1000);
  set_weight(2);
}
