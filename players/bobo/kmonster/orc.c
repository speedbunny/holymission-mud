inherit "obj/monster";                                                          
                                                                                
                                                                                
reset(arg) {                                                                    
::reset(arg);                                                                   
  if(arg) return;                                                               
  set_name("orc");                                                              
  set_race("orc");                                                              
  set_size(3);
  set_male();
  set_level(2);                                                                 
  set_hp(66);                                                                   
  set_wc(2);                                                                    
  set_ac(3);                                                                    
  set_al(-20);                                                                  
  set_short("An orc");                                                         
  set_long("An orc of the Mythwood race.\n");                                   
  set_aggressive(1);                                                            
}                                                                               
