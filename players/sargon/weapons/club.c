inherit "obj/weapon"; 
reset(arg)  
{ 
  ::reset(arg); 
    if(!arg) { 
    set_name("An Ewok's club");
    set_alt_name("club");
    set_alias("club");
    set_short("An Ewok's club.\n");
    set_long("A carefully carved club with a wide head and a narrow handle.\n");
    set_class(5);
    set_type(1); 
    set_weight(1);
    set_value(50);
    } 
} 


