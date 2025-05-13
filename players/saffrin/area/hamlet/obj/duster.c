inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if (!arg) {
     set_name("duster");
     set_short("A feather duster");
     set_long("A feather duster that has red and yellow feather billowing out from its\n"+
                "wooden base.\n");
     set_class(5);
     set_weight(1);
     set_value(2000);
  }
}
