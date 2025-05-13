 /**** GENERAL WALL IN THE NOTTINGHAM *****/
/*  coded by: Goldsun 021094    	 */

inherit "/room/room";
#define GATES "/players/goldsun/nottingham/room/gates"

status is_break;

void make_orc(int num){
int i;

 return;  /*  this is , i wanna stop 'bug' .. this lib is terrible
*/
 GATES->add_enemy(num);
 for(i=0;i<num;i++){ 
 move_object(clone_object("/players/goldsun/nottingham/monster/orc"),
			this_object());
 }
}
  

void reset(int arg){
  ::reset(arg);

if (arg) return;

 is_break=0;
 set_light(1);
 short_desc="At the town wall";
 long_desc="@@query_long@@";
 items=({"wall","@@query_wall_desc@@",
	"road","Stony town road"
        
    });
 call_out("break_wall",10);
}

query_long(){
 string str;
 

 if (!GATES->query_is_break())
     return "You are walking along the tall town wall which is made of stone.\n"+
	   "Against the wall there are small wooden cottages and\n"+
	   "houses made of brick. The town looks very peaceful.\n";
  return "You are walking along the town wall. The wall is destroyed.\n"+
         "Against the wall there are small burned cottages and houses.\n"
	 "The town is in panic. It looks as if the town is under attack.\n";
}



int break_wall(){
 return 1; /* stop orcs */
 if (GATES->query_is_break()) return 0;
 GATES->set_break(1);
 is_break=1;  /* pre query_desc */
 make_orc(random(10)+10);
 return 1;
}

query_wall_desc(){
 if (is_break) return "The wall is destroyed";
 return "The tall town wall. It looks very sturdy";
}

init(){
 ::init();

add_action("query_smell","smell");
}

query_smell(){
 if (GATES->query_is_break()) write("You smell heavy smoke in the air.\n");
  else write("You smell nothing special.\n");
 return 1;
}

