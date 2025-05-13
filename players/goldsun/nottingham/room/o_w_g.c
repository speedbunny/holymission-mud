inherit "/room/room";
#define GATESW "/players/goldsun/nottingham/room/gates_w"
#define GATES "/players/goldsun/nottingham/room/gates"

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Western gates");
 long_desc="You are standing in front of large gates, Western gates of\n"+
	   "Nottingham. It looks very sturdy.\n";


 smell="The air is fresh.";

 dest_dir=({ "/players/goldsun/nottingham/room/rw1","west"});

 items=({"gates","@@query_gates@@"
	
	});
 }
 ::reset(arg);
}

string query_gates(){
 if (GATESW->query_is_open()) return "The gates are open";
 return "Tha gates are closed";
}

init(){
 ::init();
add_action("enter","enter");
add_action("open","open");
add_action("knock","knock");
}

int knock(string str){
 notify_fail("Knock what ?\n");
 if (!str) return 0;
 if (str=="gates"){
   if  (GATES->query_number_of_enemy()>0){
    write("A voice says: Ok. You may pass.\n");
    GATESW->help_players(this_player());
    this_player()->move_player("into the town#players/goldsun/nottingham/room/gates_w");
   }  else {
    write("A voice says: Use gates. The town is free.\n");
   }
   return 1;
 }  
 return 0;
}

int open(string str){
 notify_fail("Open what ?\n");
 if (!str) return 0;
 if (str=="gates"){
   if (GATESW->query_is_open()){
       write("The gates are already opened.\n");
       return 1;
   } 
   if (GATES->query_number_of_enemy()>0){
        write("You hear a voice: The town is under attack. If you want to"+
	      " enter and\nto help us, type \"knock gates\".\n");
        return 1;
   }
   write("You open the gates.\n");
   say(this_player()->query_name()+" opens the gates.\n");
   tell_room(GATESW,"Someone opens the gates.\n");
   GATESW->set_open(1);
   return 1;
 }
 return 0;
}  

int enter(string str){
 if (str=="gates"){
  if (!GATESW->query_is_open()){
     write("The gates are closed.\n");
     return 1;
  }

  this_player()->move_player("into the town#/players/goldsun/nottingham/room/gates_w");
  return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}

