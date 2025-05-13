inherit "obj/weapon";                                                           
                                                                                
reset(arg) {                                                                    
 set_name("bow");                                                               
 set_alias("longbow");                                                          
 set_class(10);                                                                 
 set_weight(2);                                                                 
 set_value(5155);                                                               
 set_short("A longbow");                                                        
 set_long("This is a longbow usually used by centaurs.\n"+                      
    "There is something written on it.\n");                                     
 set_read("The only thing you can dechiffre is: 'Arrows at ..'\n");             
 set_hit_func(this_object());                                                   
}                                                                               
                                                                                
weapon_hit(attacker)   {                                                        
  object arrow;                                                                 
  arrow=present("xarrow",this_player());                                        
  if(!arrow) {                                                                  
    write("You swing the bow against "+attacker->query_name()+".\n");           
    say(wielded_by->query_name()+" swings the bow against "+                    
      attacker->query_name()+".\n");                                            
    if(wielded_by->query_npc()) return 20;                                      
    return 5;                                                                   
  }                                                                             
  else                                                                          
  {                                                                             
    write("You notch an arrow to the bow.\n");                                  
    say(wielded_by->query_name()+" notches an arrow.\n");                       
    if(wielded_by->query_str()<10) {                                            
      write("You're to weak to pull back the string.\n");                       
      say(wielded_by->query_name()+" is to weak to pull back the string.\n");   
      return 1;                                                                 
    }                                                                           
    else                                                                        
    {                                                                           
      write("You pull back to string and let the arrow off.\n");                
      say(wielded_by->query_name()+" pulls back the string and lets an arrow "+ 
       "off the bow.\n");                                                       
      arrow->set_power(wielded_by->query_str());                                
      arrow->throw(attacker);                                                   
      return 15;                                                                
    }                                                                           
  }                                                                             
}                                                                               
