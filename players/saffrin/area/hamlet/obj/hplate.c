inherit "/obj/armour";
    
reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("platemail");
     set_alias("plate");
     set_short("Hamlet's platemail");
     set_long("This slightly dented platemail was worn by Hamlet during many long \n"+
                    "battles.  It appears to have been made from brass.\n");
     set_ac(5);
     set_size(3);
     set_type("armor");
     set_value(2500);
     set_weight(4);
     set_size(0);
  }
}
