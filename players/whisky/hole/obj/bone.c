inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
    set_name("bone");
    set_class(12);
    set_short("A bloody human bone");
    set_long("A white bloody human bone.\n");
    set_type(1);
    set_value(100);
    set_weight(1);
    set_alias("human bone");
  }
