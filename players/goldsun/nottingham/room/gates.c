/*  coded by: Goldsun 021094    	 */

inherit "/room/room";
#define PALACE "/players/goldsun/nottingham/room/road2"
#define GATES2 "/players/goldsun/nottingham/room/outside_gates"
#define GATESW "/players/goldsun/nottingham/room/gates_w"
#define MINENEMY 2   /* how many enemies can be in the town and
			town is not under attack yet */

status is_break,is_open;
int number_of_enemy;

int query_is_break(){ return is_break; }

int query_is_open(){ return is_open; }

int query_number_of_enemy(){ return number_of_enemy; }

void set_open(int i){  is_open=i; }

void set_break(){ 
 is_break=1;
 is_open=0;
 GATESW->set_open(0);
 PALACE->set_closed(1); 
 call_out("alarm_players",2);
 }

void add_enemy(int i){ 
  
  number_of_enemy+=i; 
  if (number_of_enemy<0)   number_of_enemy=0;
  if (number_of_enemy<=MINENEMY)   is_break=0;     /* I want to rebuild town */
  
}

void alarm_players() {
int i;

object *u;
string place,*placetest;

  u = users();
  for(i=0;i<sizeof(u);i++) {
    if(environment(u[i])) place = file_name(environment(u[i]));
    placetest = explode(place,"/");
    if(placetest[1] == "goldsun" && placetest[2] == "nottingham") {
      tell_object(u[i],"Bell rings: BENG ! BING ! BONG !\n");
      }
   }
}

reset(arg){
  ::reset(arg);


if (arg) return;
 number_of_enemy=0;
 is_break=0;
 is_open=1;
 set_light(1);
 short_desc="Town gates";
 long_desc="You are at the town gates in the Nottingham. The gates\n"+
           "are made of oak wood. The town continues to the west.\n";
 smell="The air is damp and dusty."; 
 dest_dir=({ "/players/goldsun/nottingham/room/wall1", "north",
	     "/players/goldsun/nottingham/room/road1", "west",
	     "/players/goldsun/nottingham/room/wall23", "south"});

 property=({"no_clean_up"});

 items=({"gates","@@query_gates_desc@@",
	"road","Stony town road"
        
   });
}

string query_gates_desc(){
 if (is_open) return "The oak gates are open";
 else return "The oak gates are closed";
}

init(){
 ::init();
add_action("enter","enter");
add_action("open","open");
}

int open(string str){
 if (str=="gates"){
   if (is_open){
     write("The gates are already opened.\n");
     return 1;                                                    /***********/
   }
   if ((is_break) && (this_player()->query_level()<32)){ /* !check! */
     write("You are not allowed to open the gates.\n"+
           "Nottingham is still under attack.\n");
     return 1;
   }
   write("You open the gates.\n");
   say(this_player()->query_name()+" opens the gates.\n");
   tell_room(GATES2,"Someone opens the gates.\n");
   if (is_break){
     write("Warning ! Nottingham is still under attack.\n");
     call_out("set_open",5,0);
   }
   is_open=1; 
   return 1;
 }
 notify_fail("Open what ?\n");
 return 0;
}
 

int enter(string str){
 if (str=="gates"){
  if (is_open) this_player()->move_player("east#players/goldsun/nottingham/room/outside_gates.c");
  else write("The gates are closed.\n");
  return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}

