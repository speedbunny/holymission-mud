inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("A Denmark officer's sword");       
     set_long("The sword of a Denmark offiicer.  It is made from steel that has been treated\n"+
                "with a rare metal to appear red.\n");
     set_class(7);
     set_weight(2);
     set_value(2000);
  }
}
