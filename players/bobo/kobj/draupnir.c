inherit "/obj/armour";                                                          
                                                                                
status aura_on;                                                                 
object aura;                                                                    
                                                                                
reset(arg) {                                                                    
 ::reset(arg);
if (arg) return;                                                                
 set_name("draupnir");                                                          
 set_short("Draupnir"); 
 set_long("Draupnir is Odin's ring.\n"); 
 set_value(10000);
 set_weight(1);                                                                 
 set_type("ring");                                                              
 set_ac(1);                                                                     
 set_size(0);
 aura_on=0;                                                                     
}                                                                               
                                                                                
init() {                                                                        
::init();
  add_action("turn","turn");                                                    
}                                                                               

turn(str) {                                                                     
  if (!id(str)) return;                                                         
  if(!worn) {                                                                   
    write("You have to wear it, if you want to use it.\n");                     
    return 1;                                                                   
  }                                                                             
  if (!aura_on) {                                                               
    write("As you turn Draupnir a strange aura surroundes you.\n");             
    say(this_player()->query_name()+" is surrounded by a blue aura.\n");        
    aura=clone_object("players/kelly/obj/aura");                                
    move_object(aura,environment(this_player()));                               
    move_object(this_player(),aura);                                            
  } else {                                                                      
    write("As you turn Draupnir again the aura fades slowly away.\n");          
    move_object(this_player(),environment(aura));                               
    destruct(aura);                                                             
    say("The blue aura dissapears and "+this_player()->query_name()+            
        " steps out of it.\n");                                                 
  }                                                                             
  aura_on=!aura_on;                                                             
  return 1;                                                                     
}                                                                               
