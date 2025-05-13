inherit "/room/room";
#define PALACE "/players/goldsun/nottingham/room/road2"
#define GATES "/players/goldsun/nottingham/room/gates"
#include "/obj/door.h"

object obj_1,obj_2;

string query_gates_desc(){
 if (PALACE->query_is_closed()) return "The gates are closed";
 return "The gates are opened";
}

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Courtyard");
 long_desc="In the center of the courtyard. The hard and stony ground\n"+
	   "is covered with slanted rocks. The courtyard continues to\n"+
	   "north and south. The east gates leades to the town and\n"+
	   "west door to the residence of the sheriff of Nottingham.\n";
 
 smell="You smell a fresh grassy air.";

 dest_dir=({ "/players/goldsun/nottingham/room/castle/court1","north",
	     "/players/goldsun/nottingham/room/castle/court3","south" });

 MAKE_DOORS("/players/goldsun/nottingham/room/castle/hall1","east",
          "/players/goldsun/nottingham/room/castle/court2","west","steel",
          "no_code_902",
          "Massive door to the residence.\n", 1,0,0);
 
 obj_1->both_door_sound("A creak sound");

 items=({  "grass","The fresh grass looks well",
	   "flowers","The flowers looks very well",
           "green grass","Nice green grass is waving in the wind",
           "residence","It is the residence of nottingham sheriff",
           "wall","The castle wall is made of stone",
    	   "gates","@@query_gates_desc@@",
  	   "ground","It is coverd in glated rocks",
	   "glated rocks","Common glated rocks"
        });

 }
 ::reset(arg);
}

init(){
 ::init();
add_action("open","open");
add_action("close","close");
add_action("leave","leave");
add_action("do_enter","enter");
}


int do_enter(string str){
 if (str=="gates"){
    if (PALACE->query_is_closed()){
        write("The gates are closed.\n");
        return 1;
    }
    this_player()->move_player("to the town#players/goldsun/nottingham/room/road2");
    return 1;
 }
 return 0;
} 


int leave(string str){
 if (str=="castle")
   if (GATES->query_number_of_enemy()>0){
        write("The guard of gates lets you through the gates.\n");
        this_player()->move_player("to the town#players/goldsun/nottingham/room/road2");
        return 1;
   }
}

int open(string str){
 notify_fail("Open what ?\n");
 if (str=="gates"){
     if (PALACE->query_closed()==0){
       write("The gates are already opened.\n");
       return 1;
     }
     if (GATES->query_number_of_enemy()>0){
        write("You can hear a voice: There are enemies in the town !!!\n");
        write("If you want to leave this castle, type \"leave castle\".\n");
        return 1;
     }
     PALACE->set_closed(0);
     write("You open the gates.\n");
     say(this_player()->query_name()+" opens the gates.\n");
     tell_room(PALACE,"Someone opens the gates.\n");
     return 1;
 }
}


int close(string str){
 notify_fail("Close what ?\n");
 if (str=="gates"){
   if (PALACE->query_closed()) write("The gates are already closed.\n");
   else {
    write("You close the gates.\n");
    say(this_player()->query_name()+" closes the gates.\n");
    tell_room(PALACE,"Someone closes the gates.\n");
    PALACE->set_closed(1);
   }
   return 1;
 }
}
