inherit "/room/room";
#define TP this_player()
#define BOAT "players/goldsun/example/my_boat"
object talk;

void reset(int arg){


 if (!talk){
  talk=clone_object("/players/goldsun/example/my_talker");
  transfer(talk,this_object());
 }

if (!arg){
 set_light(1);
 short_desc=("On the Atlanta");
 long_desc="You are on the Atlanta.\n";
 no_obvious_msg="";
 property=({"no_fight"});
  }
 ::reset(arg);
}

init(){
 ::init();
add_action("do_leave_boat","leave");
}

int do_leave_boat(string str){
 notify_fail("Leave what?\n");      
 if (BOAT->id(str)){
  if (BOAT->query_is_harbour()){    
   this_player()->move_player(BOAT->query_name()+"#"
	+file_name(BOAT->query_boat_environment()));
   return 1;
  }
  write(BOAT->query_sailor_name()+" says: Hey you stupid dummy. "+
           "Don't leave this boat on the sea.\n");
  return 1;                            
 }
}
                                  
