inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("Claudius's sword");
     set_long("This is the sword of Claudius, king of Denmark.  It has a jeweled hilt that \n"+
                "sparkles brightly.  It has saved the king many times.\n");
     set_class(16);
     set_weight(3);
     set_value(6400);
  }
}
