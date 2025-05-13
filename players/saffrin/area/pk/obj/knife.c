inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("knife");
     set_short("Jack the Ripper's knife");       
     set_long("This is the infamous knife of Jack the Ripper.  It has blood stains "+
	      "encompassing the entire blade. The thick blood makes the knife "+
              "heavier than it appears.\n");
     set_class(17);
     set_weight(3);
     set_value(8000);
  }
}
