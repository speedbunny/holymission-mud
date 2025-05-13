inherit "obj/weapon";                                                                                                               
                                                                                                                                    
reset (arg) {                                                                                                                       
    ::reset(arg);                                                                                                                   
    if (arg) return;                                                                                                                
    set_name("shovel");                                                                                                             
    set_weight(1);                                                                                                                  
    set_value(100);                                                                                                                 
    set_short("A shovel");                                                                                                          
    set_long("The undertakers favorite tool.\n");                                                                                   
    set_two_handed();                                                                                                               
    set_type(0);                                                                                                                    
    set_class(10);                                                                                                                  
}                                                                                                                                   
                                                                                                                                    
init() {                                                                                                                            
                                                                                                                                    
                                                                                                                                    
    ::init();                                                                                                                       
    add_action("dig","dig");                                                                                                        
}                                                                                                                                   
                                                                                                                                    
dig(arg) {                                                                                                                          
    if (this_player() != environment(this_object())) return(0);                                                                     
    if (!environment(this_player())->dig()) {                                                                                       
        write("You dig a hole, just for the hell of it.\n");                                                                        
        say(this_player()->query_name()+" desperatly tries to dig a hole"+                                                          
                                        " in here and finds nothing.\n");                                                           
}                                                                                                                                   
return(1);
    }                                                                                                                               
