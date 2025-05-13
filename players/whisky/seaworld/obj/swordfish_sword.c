inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (!arg) { 
    set_name("sword");
    set_class(16);
    set_alias("swordfish sword");
    set_short("A swordfish sword");
    set_long("The strong weapon of the swordfish.\n");
    set_type(2);
    set_value(600);
    set_weight(2);
   }
 }
