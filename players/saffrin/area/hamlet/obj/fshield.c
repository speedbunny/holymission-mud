inherit "/obj/armour";

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("shield");
     set_short("Fortinbras's shield");
     set_long("A large wooden shield with the crest of the house of Norway hand painted\n"+
                "on the front.\n");
     set_ac(3);
     set_size(3);
     set_type("shield");
     set_value(1000);
     set_weight(3);
     set_size(0);
  }
}
