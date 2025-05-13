#include "../monkway.h"
inherit "obj/weapon";
  reset(arg) {
   ::reset(arg);
   if (arg) return; 
     set_name("hammer");
     set_alias("rock hammer");
     set_short("A big rock hammer");
     set_long("The hammer of a stone golem\n"+
              "to cut rocks.\n");
     set_weight(20);
     set_type(1);
     set_class(15);
     set_value(100);
     set_hit_func(TO);
   }
   weapon_hit(ob) {
    if ((random(100) < 8)){
     write("K N A C K  You smash "+ob->query_name()+" you with your hammer.\n");
     say("K N A C K  "+TPN+" smashes "+ob->query_name()+" with "+TPP+" hammer.\n");
    return 20;
    }
   return;
  }
  init() {
   add_action("cut","cut");
   add_action("cut","smash");
   ::init();
   }
  
  cut(arg) {
    object ob; 
    if (ob=present("rock",environment(TP)) && (arg=="rock")) {
        ob=present("rock",environment(TP));
       switch(random(4)) {
         case 0:
         tell_room(environment(TP),""+TPN+" smashes "+TPP+" hammer against the big rock.\n\nK N A C K  big stone pieces are cutted out from the rock.\n");
         break;
         case 1: 
         tell_room(environment(TP),""+TPN+" smashes "+TPP+" hammer against the big rock.\n\nK N A C K   a big stonepiece is cutted out from the rock.\n");
         break;
         case 2:
         tell_room(environment(TP),""+TPN+" smashes "+TPP+" hammer against the big rock.\n\nK N A C K   a little stonepiece is cutted out from the rock.\n");
         break;
         case 3:
         tell_room(environment(TP),""+TPN+" smashes "+TPP+" hammer against the big rock.\n\nK N A C K    K N A C K     B U M M  the rock falls into tiny pieces.\n");   destruct(ob);
       return 1;
      }
      return 1;
     }
     write("What ??\n");
   return 1;
  }
    
     
     
