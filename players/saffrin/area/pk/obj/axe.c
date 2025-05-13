inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("axe");
     set_short("Lizzie Borden's axe");       
     set_long("This is the infamous axe of Lizzie Borden.  She used it "+
	      "to chop her family to pieces.\n");
     set_class(10);
     set_weight(2);
     set_value(3000);
  }
}
