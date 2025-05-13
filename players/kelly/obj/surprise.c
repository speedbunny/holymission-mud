status power;
string name;
                                                                                
init() {                                                                        
 add_action("open","open");                                                     
 add_action("set","set");
 add_action("close","close");                                                   
 add_action("surprise","surprise");
 add_action("power","power");
  enable_commands();                                                            
}                                                                               
                                                                                
query_weight() { return 1000; }                                                 
                                                                                
id(str) {                                                                       
  return (str=="box" || str=="surprise box" || str=="great box" || str=="opening");               
}                                                                               
                                                                                
short() {                                                                       
  return "A great box";                                                         
}                                                                               
                                                                                
long(str) {                                                              
  if(str=="opening") {
     write("A strange hole.\n");
     return;
  }          
  write("This is a surprising box.\n");                                         
  write("It is big, heavy and has the shape of a cube.\n");                     
  write("There  is a strange opening on the box.\n");
}                                                                               
                                                                                
open(str) {                                                                     
  if(!id(str)) return;                                                          
  write("Sorry, this function is not yet supported.\n");                        
  return 1;                                                                     
}                                                                               
                                                                                
close(str) {                                                                    
  if(!id(str)) return;                                                          
  write("Sorry, this function is not yet supported.\n");                        
  return 1;                                                                     
}                                                                               
                                                                                
catch_tell(str) {                                                               
  string s1,s2,s3,s4;                                                           
  object me;                                                                    
  sscanf(str,"%s %s %s %s",s1,s2,s3,s4);                                        
  me=find_player("kelly");                                                      
  if(s2=="enters")  {
    if(s1==name) 
    if(me && power)
      tell_object(me,str);                                            
    write("Welcome "+s1+"!\n");                                               
    write("Nice mudding.\n");                                                 
    if(s1=="Kelly" || s1=="Marc")
      shout(s1+" just entered the game.\nSomehow you feel happy "+            
        "about this.\n");                                                     
  }                                                                         
  return 1;                                                                     
}                                                                               

surprise(str) {
  if(!check_kelly()) return 1;
  if(!str) { 
     write("Whom do you want do surprise?\n");
      return;
  }
  name=str;
  write(capitalize(str)+" will be surprised when entering!\n");
  return 1;
}

check_kelly() {
  if(this_player()->query_real_name()!="kelly") {
     write("Sorry, this box can only be used by the one who build it.\n");
     return 0;
  }
  return 1;
}

grab_him(str) {
  object who;
  who=present(str,environment(this_object()));
   if(who) {
      say("The box grows arms, grabs "+who->query_name()+", and throws "+
             who->query_objective()+" out of the game.");
      say("You can dirty laughing from the inside of the box.");
    }
    return 1;
}

power(arg) {
  if(!check_kelly()) return;
  if(!arg)
     power=!power;
  if(arg=="on" || arg=="1")
     power=1;
  if(arg=="off" || arg=="0") 
     power=0;
   write("The box is now ");
   if(power) write("ON");
   else write("OFF");
   write("\n");
   return 1;
}
