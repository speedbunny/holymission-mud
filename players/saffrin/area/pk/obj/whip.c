inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("whip");
     set_short("Marquis de Sade's whip");       
     set_long("This is the infamous whip of the Marquis de Sade.  It is has been "+
	      "made from black leather.\n");
     set_class(10);
     set_weight(2);
     set_value(3000);
  }
}
