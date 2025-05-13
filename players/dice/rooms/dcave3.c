inherit "/room/room";
#include "/players/goldsun/sherwood/dig.h"
#include "/players/patience/GenObj/move_blocked.h"

object man,gem,m;
int i;

reset(arg){
 ::reset();
 if (!man){
   man=clone_object("/players/goldsun/sherwood/monster/saliman");
   transfer(man,this_object());
   m=clone_object("/obj/money");
   m->set_money(random(10000));
 
   gem=clone_object("/players/goldsun/sherwood/obj/gem");
   move_blocked(m,this_object(),man);
   }

if (arg) return;
 set_light(0);
 short_desc=("A bear's cave");
 long_desc=("You are in the dark bear cave.\n"
	   +"This place is not save for you.\n");
 smell="You feel bear's smell";

 dest_dir=({"/players/goldsun/sherwood/room/shwood20","up"});
 items=({"cave","Dark highwayman's cave",
         "dark cave","This is Saliman's treasury",
	 "highwayman's cave","This is Saliman's treasury",
	 "treasury","You can see a lot of gold, silver, diamonds",
	 "gold","Yellow valuable metal",
	 "silver","The valuable metal",
	 "diamonds","They are very nice and valuable",
	 "diamond","It is very valuable"});
 }
 
init(){
 ::init();
add_action("dig","dig");
}

