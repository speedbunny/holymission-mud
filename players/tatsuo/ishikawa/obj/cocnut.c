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
