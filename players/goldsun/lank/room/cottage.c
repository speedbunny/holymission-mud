inherit "/room/room";
#include "/players/goldsun/stand.h"
#define COAST "/players/goldsun/lank/room/coast4"
#define COTT  "/players/goldsun/lank/obj/cott"

status is_fire;

int query_fire(){ return is_fire; }

void end_fire(){  /* we have to change cott to ash */
 if (!is_fire) return;
 COTT->kamikadze();
 move_object(clone_object("/players/goldsun/lank/obj/ash"),COAST);
 tell_room(COAST,"The cottage burns to the ash.\n");
 is_fire=0; 
}

void start_fire(){
 object *p,fl;
 int psiz, j;

    is_fire=1;
    p=all_inventory(this_object());
    psiz=sizeof(p);
    for(j=0;j<psiz;j++) {
        if (living(p[j]) && !(p[j]->query_npc())){
            fl=clone_object("/players/goldsun/lank/obj/goldsun_flames");
            transfer(fl,p[j]);
            fl->start_burning(p[j],100);
        }
    }
    call_out("end_fire",10);
}
 

 
void reset(int flag) {
  if (!flag) {
    short_desc = "In the cottage";
    long_desc  =
 "You are in the old wooden cottage. It seems to be sailor cottage.\n"
+"There are table with several chairs in the middle of the cottage.\n"
+"In the corner you can see old sailor chest. \n";

    set_light(1);
    is_fire=0;
    items = ({"table","Old wooden table",
	      "chair","Old wooden chair",
	      "chairs","Old wooden chairs",
	      "chest","Old sailor chest. It is made from wood.\n"+
			"Maybe there is something in it",
	      "wood","The wood is wery dry. DON'T LIGHT IT"
      });
  }
}

init() {
  ::init();
  add_action("light","light");
}

light(str){

 if (present("lighted_torch",TP)){
   if (str=="wood" || str=="cottage" || str=="table" ||
	str=="chair" || str=="chest" || str=="chairs"){

       write("You light the cottage.\n");
       say(OPN+" lights the cottage.\n");
       tell_room(COAST,"The cottage starts to burn.\n");

       start_fire();

      return 1;
   }
  notify_fail("Light what ?\n");
  return 0;
 }
 write("You have nothing to light it with.\n");
 return 1;
 }

