inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("sword");
    set_alt_name("sword");
    
    set_short("Kunoh's wooden sword");
   set_long("This is Kunoh's wooden sword...despite its material\n" +
	    "it is quite powerful due to its weapon magic.\n");
 
    set_type(2);
    set_class(4);
    set_value(15000);

    set_weight(3);
    
  }
}
