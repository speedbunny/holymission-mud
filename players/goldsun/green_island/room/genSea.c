inherit "/room/room";
#include "/players/goldsun/stand.h"
#define TO this_object()

reset(arg){
if (arg) return;
 set_light(1);
 short_desc=("In the sea");
 long_desc="You are swimming in the sea near the coast of Green Island.\n";

 property=({"has_water"});

 smell="You smell fresh and salty sea air.";

 items=({ "sea","It extends to the horizon"
	  
         });
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("drink","drink");
  add_action("swim","swim");
  add_action("dive","dive");
  add_action("drop","drop");
  }

int dive(){
 write("You can't do that; you wouldn't be able to breathe!\n");
 return 1;
}

void diving(string str){
    if (present(str,TO)){
       destruct(present(str,TO)); 
       write("Bulp.\n"+capitalize(str)+" dives down into the sea.\n");
    } else
    if (present("coins",TO)){
       destruct(present("coins",TO));
       write("Bulp.\nCoins dive down.\n");
   }

}


int drop(string str){
  if (str=="all"){
      write("You cannot drop all, you have to swim !\n");
      return 1;
  }
  call_out("diving",3,str);   /*  a little risk */
  TP->drop(str); 
}

int swim(){
  write("But you are already swimming.\n");
  return 1;
 }

int drink(string arg){
  if (!arg) return 0;
  if (arg=="water" || arg=="salt water" || arg=="clear water" ||
   	 arg=="clear salt water" || arg=="water from sea"){
   write("As you drink some salty water from the sea, you get a bad"
    +"feeling.\n");
   TP->add_poison(3);
   say(OPN+" drinks some water.\n");
   return 1;
   }
  }

int lsten(){
      write("You can hear a sheep sound.\n"); 
  return 1;
  }              

