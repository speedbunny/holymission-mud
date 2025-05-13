inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("Fortinbras's sword");
     set_long("This jewel encrusted sword is the sword of the Prince of Norway.  It is \n"+
                "tarnished and worn from fighting many battles.\n");
     set_class(16);
     set_weight(3);
     set_value(6400);
  }
}
