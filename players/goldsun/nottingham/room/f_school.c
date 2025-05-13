#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
#define PATH "/players/goldsun/nottingham/room/"

inherit "/room/room";

#include "/players/whisky/genesis/sys/break_string.h"


void reset (int arg){
object chest,gc;

  if (!present("chest",TO)){
    chest=clone_object("/players/goldsun/nottingham/obj/f_chest");
    gc=clone_object("/obj/money");
    gc->set_money(9500+random(2000));
    transfer(gc,chest);
    transfer(chest,TO);
    chest->set_closed();
    chest->set_locked();
  } else {
    chest=present("chest",TO);
    gc=clone_object("/obj/money");
    gc->set_money(9500);
    move_object(gc,chest);
    chest->set_closed();
    chest->set_locked();
  }

if (!arg){

 move_object("/players/goldsun/nottingham/monster/master",TO);
 move_object("/players/goldsun/nottingham/monster/robert",TO);
 move_object("/players/goldsun/nottingham/monster/akimo",TO);
 move_object("/players/goldsun/nottingham/monster/hassan",TO);
 
 set_light(1);

 short_desc="In the training room";

 long_desc= break_string("You are in the training room where the master of the fencing "+
      "school trains his students. You can fight him here also. "+
      "There is a wooden sign on the wall.\n",
	65);

 items = ({"sign"," A wooden sign. There is something written on it",
          "floor", "It is a polished hardwood floor"
        });

 smell = "You smell perspiration in the air";

 property = ({"no_fight","no_teleport"});
 no_obvious_msg="";

  }
 ::reset(arg);
}

init(){
 ::init();
add_action("read","read"); 
}

int read(string str){
  if (str=="sign"){
    write("Fencing school\n");
    return 1;
  }
  notify_fail("Read what ?\n");
  return 0;
}

