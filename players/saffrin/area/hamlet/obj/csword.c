inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("Courtier's sword");
     set_long("The sword of a flashy courtier from the court of Denmark.  It is heavily jeweled\n"+
                "with gems from around the world.\n");
     set_class(10);
     set_weight(2);
     set_value(4000);
  }
}
