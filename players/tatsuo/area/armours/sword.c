inherit "obj/weapon";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

    set_name("A wolfen sword");
    set_alias("sword");
    set_short("sword");
 set_long("This sword is of excellent craftsmanship.  From the runes on the\n"+
	  "hilt and blade, you think it is of wolfen make.\n");
    set_class(18);
    set_value(5000);
    set_weight(4);

}


