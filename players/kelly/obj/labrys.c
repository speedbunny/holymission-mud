inherit "obj/weapon";                                                           
                                                                                
reset(arg) {                                                                    
 set_name("labrys");                                                        
 set_alias("axe");                                                            
 set_alt_name("waraxe");
 set_class(15);                                                                 
 set_weight(8);
 set_value(1250);
 set_short("A labrys"); 
 set_long("This is a heavy twohanded and twobladed waraxe.\n");        
 set_two_handed();
 set_type(1);
 /* set_hit_func(this_object()); */ 
}                                                                               
                                                                                
weapon_hit(attacker)   {                                                        
}                                                                               
