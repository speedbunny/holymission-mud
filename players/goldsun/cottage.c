inherit "/room/room";
#include "/players/goldsun/stand.h"
status is_fire;

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
  object *p,fl;
  int psiz, j;

 if (present("lighted_torch",TP)){
  if (str=="wood" || str=="cottage" || str=="table" ||
	str=="chair" || str=="chest" || str=="chairs"){
    is_fire=1;
    write("You light the cottage.\n");
    say(OPN+" lights the cottage.\n");
/*    tell_room("/players/goldsun/lank/coast4","The cottage starts to burn.\n");
  */  write("povedal\n");

    p=all_inventory(this_object());
    psiz=sizeof(p);
    for(j=0;j<psiz;j++) {
      if (living(p[j]) && !(p[j]->query_npc())){
       fl=clone_object("/players/goldsun/lank/obj/goldsun_flames");
       transfer(fl,p[j]);
       fl->start_burning(p[j],500);
      }
     }
    call_out("end_fire",10);
    return 1;
  }
  write("Light what ?\n");
  return 1;
 }
 write("You have nothing to light it with.\n");
 return 1;
 }
int query_fire(){ return is_fire;}

int end_fire(){
     is_fire=0;
    return 1;
    }


