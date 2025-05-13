inherit "/obj/armour";
  
reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("boots");
     set_short("Hamlet's boots");
     set_long("These fine pair of hand crafted boots have travelled upon many\n"+
                    "roads on Hamlet's feet.\n");
     set_ac(1);
     set_size(3);
     set_type("boot");
     set_weight(2);
     set_value(1000);
     set_size(0);
  }
}
