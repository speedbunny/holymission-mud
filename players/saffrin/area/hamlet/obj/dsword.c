inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("sword");
     set_short("A Denmark sword");       
     set_long("The sword of a Denmark soldier.  It is made from steel that has been treated\n"+
                "with a rare metal to appear blue.\n");
     set_class(5);
     set_weight(1);
     set_value(2000);
  }
}
