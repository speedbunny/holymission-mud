inherit "obj/weapon";
      
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("Hamlet's Sword");
     set_long("The sword of the Prince of Denmark.  It is made from the strongest\n"+
                    "metals found in the world.\n");
     set_class(20);
     set_weight(4);
     set_value(9000);
  }
}
     
