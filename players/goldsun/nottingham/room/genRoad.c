 /**** GENERAL ROAD IN THE NOTTINGHAM *****/
/*  coded by: Goldsun 021094    	 */

inherit "/room/room";
#define GATES "/players/goldsun/nottingham/room/gates"
  

query_long(){
 if (!GATES->query_is_break()) 
    return "You are walking on the stony road among the cottages"+
	   "and houses. They are made of brick, stone and wood. A sign "+
           "hanging on a house wall saying:"+" '"+short_desc+"'. "+
           "The city looks peaceful.\n";

 return "You are walking on the stony road among the cottages"+
	"and houses. A lot of them are burned and destroyed. "+
 	"The town is in panic. It looks as if Nottingham is "+
	"under attack. A sign hanging on a house wall saying:"+
        " '"+short_desc+"'.\n";

}


reset(arg){
  ::reset(arg);

if (arg) return;
 set_light(1);
 long_desc="@@query_long@@";
 items=({
	"cottage","@@query_cott_desc@@",
	"house","@@query_cott_desc@@",
	"sign","@@query_sign@@",
	"road","Stony town road",
    });
}


string query_sign(){  
  return "A copper sign. There is written : '"+short_desc+"'"; 
}

string query_cott_desc(){
 if (GATES->query_is_break()) return "It is burned to ashes";
 return "It is made of wood and bricks";
}

init(){
 ::init();
add_action("smell","smell");
add_action("enter","enter");
}

int smell(){
 if (GATES->query_is_break()) write("You smell heavy smoke in the air.\n");
  else write("You smell nothing special.\n");
 return 1;
}
  
int enter(string str){
 if (str=="cottage" || str=="house"){
  write("There is no entrance to the "+str+" from here.\n");
  return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}
