inherit "/obj/treasure";
#include "/players/goldsun/stand.h"
reset(arg){
 ::reset(arg);
if (arg) return;

 set_id("clay");
 set_short("A heap of clay");
 set_long("A heap of clay.\n"
	  +"Someone has dig this clay.\n");
 set_weight(1);
 set_value(0);
 }
       /*
init(){
 ::init();
 add_action("_get","get");
 add_action("_get","take");
}
         */
get(){
 write("The clay slips through your fingers.\n");
 say(OPN+" tries to take a heap of clay.\n");
 return 0;
}

