inherit "/players/goldsun/nottingham/room/genRoad";
#define PATH "/players/goldsun/nottingham/room/"
#define GATES "/players/goldsun/nottingham/room/gates"
#define COURT "/players/goldsun/nottingham/room/castle/court2"

status is_closed;

void set_closed(int i){ is_closed=i; }     /* 1=closed, 0=opened */

int query_closed(){ return is_closed; }

string query_gates_desc(){
 if (is_closed) return "The gates are closed";
 return "The gates are opened";
}
  

query_long(){
 if (!GATES->query_is_break()) 
    return "You are walking on the stony road among the cottages"+
	   "and houses. They are made of brick, stone and wood. "+
           "There are huge castle gates to the west. A sign "+
           "hanging on a house wall saying:"+" '"+short_desc+
           "'. The city looks peaceful.\n";

 return "You are walking on the stony road among the cottages"+
	"and houses. A lot of them are burned and destroyed."+
        "There are huge castle gates to the west. The town is"+
        "in panic. It looks as if Nottingham is under attack. "+
        "A sign hanging on a house wall saying:"+
        " '"+short_desc+"'.\n";

}


reset(arg){
 ::reset(arg);

if (arg) return;
 is_closed=1;                      /* castle is closed now */
 short_desc="Castle Road";
 dest_dir=({ PATH + "road1", "east",
	     PATH + "road15","north",
	     PATH + "road3", "south" });

 items+=({"gates","@@query_gates_desc@@",
	  "castle","It is residence of Nottingham sheriff"});

}

init(){
 ::init();
 add_action("do_enter","enter");
 add_action("open","open");
 add_action("close","close");
}

int do_enter(string str){
 if (str=="castle" || str=="gates"){
    if (is_closed){
        write("The gates are closed.\n");
        return 1;
    }
    this_player()->move_player("into the castle#players/goldsun/nottingham/room/castle/court2");
    return 1;
 }
 return 0;
} 

int open(string str){
 notify_fail("Open what ?\n");
 if (str=="gates"){
     if (is_closed==0){
       write("The gates are already opened.\n");
       return 1;
     }
     if (GATES->query_number_of_enemy()>0){
        write("You can hear a voice: There are enemies in the town !!!"+
	 "Find Upper guard\nand kill them.\n");
        return 1;
     }
     is_closed=0;
     write("You open the gates.\n");
     say(this_player()->query_name()+" opens the gates.\n");
     tell_room(COURT,"Someone opens the gates.\n");
     return 1;
 }
}


int close(string str){
 notify_fail("Close what?\n");
 if (str=="gates"){
   if (is_closed) write("The gates are already closed.\n");
   else {
    write("You close the gates.\n");
    say(this_player()->query_name()+" closes the gates.\n");
    tell_room(COURT,"Someone closes the gates.\n");
    is_closed=1;
   }
   return 1;
 }
}

