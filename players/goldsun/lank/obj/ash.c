inherit "/obj/treasure";
#include "/players/goldsun/stand.h"
reset(arg){
 ::reset(arg);
if (arg) return;

 set_id("ash");
 set_short("A big heap of ash");
 set_long("A big heap of ash from cottage.\n");
 set_weight(1);
 set_value(0);
 }

get(){
 write("The ash slips through your fingers.\n");
 say(OPN+" tries to take a heap of ash.\n");
 return 0;
}

