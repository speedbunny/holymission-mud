
/* Gambit - Barbarian Guild */

inherit "obj/armour";

#include "/players/darastor/guild/barb.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {

	set_name("lion hide");
	set_alias("hide");
	set_type("cloak");
    	set_ac(1);
	set_size(0);
	set_short("Lion hide");
	set_long("The lion hide consists of the hide and fur of a lion\n"+
		 "along with its claws and head.\n");
	set_value(1000);
	set_weight(3);
  }
}

init(){
  ::init();
  add_action("_wear","wear");
}

_wear(arg){
  if(arg=="fur" || arg=="lion fur"){
   if(this_player()->query_guild()==11){
     return 0;
     }
   else{
   write("Only barbarians may wear such armour.\n");
   return 1;
   }
  return 0;
 }
}


