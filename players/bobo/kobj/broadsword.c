inherit "obj/weapon";                                                           
                                                                                
reset(arg) {                                                                    
 set_name("broadsword");                                                        
 set_alias("sword");                                                            
 set_class(15);                                                                 
 set_weight(3);                                                                 
 set_value(1250);                                                               
 set_short("An Faunen broadsword");                                             
 set_long("This is an Faunen broadsword,with a big sea-snake on it.\n");        
 set_hit_func(this_object());                                                   
}                                                                               
                                                                                
weapon_hit(attacker)   {                                                        
 if (call_other(attacker, "id", "snake")) {                                     
   write("The broadsword loves to kill snakes, and glows softly.\n");           
   return 45;
 }                                                                              
 if (call_other(attacker,"id","faun")) {                                        
   write("Your sword will not attack a faun, because a faun made it.\n");       
   write("The sword jumps from your grip!\n");                                  
   call_other(wielded_by,"stop_wielding");                                      
  }                                                                             
}                                                                               
