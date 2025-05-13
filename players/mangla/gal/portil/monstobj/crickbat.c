inherit "obj/weapon";

  reset(arg) {
   ::reset(arg);
   if (arg) return;

    set_name("bat");
    set_alias("cricket bat");
    set_short("A cricket bat");
    set_long("It is a smooth cricket bat made from willow.\n");
    set_class(10);
    set_value(600);
    set_weight(3);
   }
