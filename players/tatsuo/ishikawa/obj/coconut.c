inherit "obj/food";
#include "/players/tatsuo/def.h"
int open;
reset(arg){
 ::reset();
if(arg) return;
set_name("coconut");
set_short("A Coconut");
set_long("A very hard coconut, you could break it to eat it, or throw it at someone.\n");
set_value(60);
}
init(){
 ::init();
AA("_break","break");
AA("_eat","eat");
AA("_throw","throw");
}
_break(arg){
if(arg=="coconut"){
 open=1;
  write("You smash the coconut against your forhead cracking it open [the coconut]");
 write("\n");
  return 1;
}
else return 0;
}
_eat(arg){
if(arg=="coconut"){
 if (open==1){ 
 write("You suck the milky white juice from your coconut.\n");
  call_out("burp",10);
 destruct(this_object());
  return 1;
  }
  else{
  write("The coconut need to be opened, maybe you could break it.\n");
   return 1;
  }
return 0;
}
}
int burp(){
  write ("Burp..\n");
}
