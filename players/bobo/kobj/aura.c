short() { return "A blue,glowing ball of light"; }                              
long() {                                                                        
  write("You're inside of a blue,glowing ball of light.\n"+                     
        "Outside you can see:\n");                                              
  call_other(environment(this_object()),"long");                                
}                                                                               
id(str) { return str=="ball"; }

                                                                                
init() {                                                                           
  add_action("commands","ddo");                              
}                                                                               
                               
commands(str) {
  if(!str) return 1;
  call_other(environment(),str);
  return 1;
}                                                                                
