/*  coded by: Goldsun 121194    	 */

inherit "/room/room";
#define GATES "/players/goldsun/nottingham/room/gates"
#define GATESO "/players/goldsun/nottingham/room/o_w_g"


status is_break,is_open;

int query_is_open(){ return is_open; }

void set_open(int i){  is_open=i; }

void help_players(object ob) {
int i;
object *u;
string place,*placetest;

  u = users();
  for(i=0;i<sizeof(u);i++) {
    if(environment(u[i])) place = file_name(environment(u[i]));
    placetest = explode(place,"/");
    if(placetest[1] == "goldsun" && placetest[2] == "nottingham") {
    tell_object(u[i],"Guard shouts: "+ob->query_name()+" arrives to help you!\n");
      }
   }
}

reset(arg){
  ::reset(arg);


if (arg) return;
 is_open=1;
 set_light(1);
 short_desc="Western town gates";
 long_desc="You are at the western town gates in the Nottingham.\n"+
           "The massive gates are made of oak wood. The town\n"+
           "continues to the east.\n";
 smell="The air is damp and dusty."; 
 dest_dir=({ "/players/goldsun/nottingham/room/wall11", "northeast",
	     "/players/goldsun/nottingham/room/road18", "east",
	     "/players/goldsun/nottingham/room/wall13", "southeast"});
             
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
   if ((GATES->query_is_break()) && (this_player()->query_level()<32)){ /* !check! */
     write("You are not allowed to open the gates.\n"+
           "Nottingham is still under attack.\n");
     return 1;
   }
   write("You open the gates.\n");
   say(this_player()->query_name()+" opens the gates.\n");
   tell_room(GATESO,"Someone opens the gates.\n");
   if (GATES->query_is_break()){
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
  if (is_open) this_player()->move_player("west#players/goldsun/nottingham/room/o_w_g");
  else write("The gates are closed.\n");
  return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}

