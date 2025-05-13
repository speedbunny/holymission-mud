inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("ruler");
    set_alt_name("ruler");
    
    set_short("Teacher's metre stick");
    set_long("Teacher's metre stick might look flimsy but it sure does\n"+
             "smart when rapped against your knuckles!\n");
 
    set_type(2);
    set_class(6);
    set_value(2000);
    set_weight(3);
    
  }
}
