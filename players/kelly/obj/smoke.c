long() { write("You're standing in the middle of a puff of smoke.\n");          
         write("The only thing you see is smoke, nothing else");                
}                                                                               
                                                                                
init() {                                                                        
 add_action("mylook","look");                                                   
}                                                                               
                                                                                
mylook() {                                                                      
  long();                                                                       
}                                                                               
                                                                                
                                                                                
vanish() {                                                                      
  say("The smoke slowly gets lighter and disappears.\n");                       
  destruct(this_object());                                                      
}                                                                               
