inherit "obj/weapon";

  reset(arg) {
   ::reset(arg);
   if (arg) return;

    set_name("claw");
    set_alias("sparrow claw");
    set_short("A sparrow claw");
    set_long("The claw from a dead sparrow.\n");
    set_class(4);
    set_value(30);
    set_weight(1);
   }
