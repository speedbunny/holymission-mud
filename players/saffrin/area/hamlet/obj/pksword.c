inherit "obj/weapon";
      
reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("Player King's sword");
     set_long("This is the sword of the Player King.  It is made from tin and has small dents\n"+
                    "all along the blade.\n");
     set_class(2);
     set_weight(1);
     set_value(800);
  }
}
