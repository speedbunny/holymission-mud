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
    this_player()->hit_player(10);                                              
    destruct(this_object());                                                    
    return 1;                                                                   
}                                                                               
                                                                                
throw(str) {                                                                    
  object victim;
  string whom,what;

  if(sscanf(str,"%s at %s",what,whom)!=2 && !id(str)) 
    
  if(id(str)) {
    write("Pufff!\n");
    write("You throw the berry to the ground and it explodes in a puff"+
    " of smoke.\n"); 
    destruct(this_object());
    return 1;
  }
  if(!id(what)) return; 
  victim=present(whom,environment(this_player()));
  if(!victim) {
    write("That is not here.\n");
    return 1;
  }
  write("You throw a berry against "+capitalize(whom)+".\n");
  say(this_player()->query_name()+" throws a berry against "+whom+".\n");

  victim->hit_player(10);
}                                                                               
                                                                                
prevent_insert() { return 1; }                                                  
