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
/*      If player is bellow lev 10, the shovel disappears                                                                           
         Let's kick quest cheaters butt a bit, Apr,1996,++Dragonn*/                                                                 
   if(this_player()->query_level()<10){                                                                                             
      destruct(this_object());                                                                                                      
      write("The shovel disappears.\n");                                                                                            
    }                                                                                                                               
}                                                                                                                                   
                                                                                                                                    
init() {                                                                                                                            
                                                                                                                                    
                                                                                                                                    
    ::init();                                                                                                                       
    add_action("dig","dig");                                                                                                        
    add_action("xxx","drop");  //No droping this item  Apr,96,Dragonn                                                               
    add_action("give","give");  //No giving this item Apr,96,Dragonn                                                                
}                                                                                                                                   
                                                                                                                                    
dig(arg) {                                                                                                                          
    if (this_player() != environment(this_object())) return(0);                                                                     
    if (!environment(this_player())->dig()) {                                                                                       
        write("You dig a hole, just for the hell of it.\n");                                                                        
        say(this_player()->query_name()+" desperatly tries to dig a hole"+                                                          
                                        " in here and finds nothing.\n");                                                           
}                                                                                                                                   
    }                                                                                                                               
/* Im fighting with quest cheaters, April,96,Dragonn                                                                                
     AHHH thos poor players.. they can't even give                                                                                  
      and drop shovel ... have fun   */                                                                                             
  xxx(str){                                                                                                                         
   if(str=="shovel"){                                                                                                               
    write("You can not drop this item.\n");                                                                                         
say(this_player()->query_real_name()+" tried to drop item but fails.\n");                                                           
    return 1;                                                                                                                       
   }                                                                                                                                
  }                                                                                                                                 
  give(arg){                                                                                                                        
    write("You cannot give this item!\n");                                                                                          
say(this_player()->query_real_name()+" tried to give something, but fails.\n");                                                     
    return 1;                                                                                                                       
 }                                                                                                                                  
