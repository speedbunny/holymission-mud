inherit "obj/food";                                                             
                                                                                
reset() {                                                                       
  set_short("A berry");                                                         
  set_long("A strange looking berry, maybe you can eat it or something"+        
   "else.\n");                                                                  
  set_name("berry");                                                            
  set_eater_mess("Mmmm. Not bad, indeed!\n");                                   
  set_eating_mess(" eats a berry.\n");                                          
  set_strength(15);                                                             
}                                                                               
                                                                                
init() {                                                                        
 ::init();                                                                      
  add_action("crunch","crunch");                                                
  add_action("throw","throw");                                                  
}                                                                               
                                                                                
crunch(str) {                                                                   
  if(!id(str)) return;                                                          
    write("Pufffff!\n");                                                        
    write("As you try to crunch the berry, it explodes in your hand"+           
     " and hurts you badly.\n");                                                
    this_player()->set_hp(call_other(this_player(),"query_hp",0)*0,75);         
    destruct(this_object());                                                    
    return 1;                                                                   
}                                                                               
                                                                                
throw(str) {                                                                    
  if(!id(str)) return;                                                          
   write("Pufff!\n");                                                           
   write("You throw the berry to the ground and it explodes in a puff"+         
    " of smoke.\n");                                                            
   destruct(this_object());                                                     
   move_object(clone_object("players/kelly/obj/smoke"),this_object());          
   return 1;                                                                    
}                                                                               
                                                                                
prevent_insert() { return 1; }                                                  
