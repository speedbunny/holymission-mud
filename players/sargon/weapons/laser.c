inherit "obj/weapon"; 
reset(arg)  
{ 
  ::reset(arg); 
    if(!arg) { 
    set_name("Stormtroopers laser"); 
    set_alt_name("laser"); 
    set_alias("laser"); 
    set_short("Laser\n"); 
    set_long("This is the weapon of choice for the Imperial Guard.\n"); 
    set_class(16); 
    set_type(1); 
    set_weight(4); 
    set_value(200); 
    } 
} 


