inherit "/obj/treasure";
#define ROAD "players/goldsun/white_tower/room/vall_road"
#define TP this_player()

reset(arg){
 if (arg) return;
 set_id("scroll");
 set_short("A scroll");
 set_long("An old scroll with black seal on it.\n");
 set_weight(1);
 set_value(0);
 }

drop(){
 write("The scroll crumbles to dust.\n");
 destruct(this_object());
 return 1;
}

init(){
 ::init();
add_action("read","read");
}

int read(string str){
 notify_fail("Read what?\n");
 if (str=="scroll"){
   if (file_name(environment(TP))==ROAD){
     write("You read the scroll.\n"+
           "Black forces screams.\n");
     ROAD->no_curse();
   } else {
     write("You read the scroll.\n"+
           "The scroll dissapears and nothing happens.\n");
   }
   say(TP->query_name()+" reads a scroll.\n");
   destruct(this_object());
   return 1;
  }
 return 0;
}  
   
