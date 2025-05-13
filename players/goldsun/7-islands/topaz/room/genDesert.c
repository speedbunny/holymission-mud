inherit "room/room";
#define MASTER "players/goldsun/7-islands/topaz/room/coast1"


void make_storm(){
 write("A fucking storm arrives.\n");
 return;
}

query_long(){
 if (1<2) 
    return "A desert\n";

 return "hehe";
}
void reset(int i){
 ::reset(i);
 if (!i){
   set_light(1);
   short_desc=("A desert");
   long_desc="@@query_long@@";
   items=({"desert",long_desc,
   	   "island",long_desc,
 	   "ground","The ground consists of sand",
	   "sand","The sand is light yellow",
	   "light yellow sand","The sand is pleasant warm",
	   "hills","Sandy hills",
	   "hill","sandy hill alias Duna !!!"
   });
 }
 ::reset(i);
}

heart_beat(){
 if (random(10)<2) make_storm();
 tell_object(find_player("goldsun"),"hello\n");
// if (!test_if_any_here()) set_heart_beat(0);
 return;
}

init(){
 ::init();
set_heart_beat(1);
add_action("do_get","get");
}
 
int do_get(string str){
  if (str=="sand"){
   write("The sand slips through your fingers.\n");
   say(this_player()->query_name()+ "tries to take the sand.\n");
   return 1;
  }
 }
