inherit "/obj/treasure";
#define COTT "players/goldsun/green_island/room/cottage"
#define TP this_player()

int is_water;

void long(){
 if (is_water) write("A bucket. It is full of water.\n");
  else write("A bucket. It looks water resistant.\n");
}

 reset(arg){
  ::reset(arg);
  
 if (arg) return;
 set_name("bucket");
 is_water=0;
 set_short("A bucket");
 set_value(10);
 set_weight(1);
 }

init(){
 ::init();
 add_action("pour","pour");
 add_action("scoop","scoop");
}


int scoop(string str){
 string what,where;
 
  notify_fail("Scoop what where?\n");
  if (!str) return 0;
  if ((sscanf(str,"%s into %s",what,where)==2) ||
      (sscanf(str,"%s in %s",what,where)==2) )
     if (what=="water" && where=="bucket"){
       if ( environment(TP)->query_property("has_water") ){
	 if (is_water){
             write("The bucket is already full of water.\n");
             return 1;
         }
         is_water=1;
         write("You scoop water into your bucket from the well.\n");
         say(TP->query_name()+" scoops water into a bucket.\n");
         return 1;
       }
       write("You fail to scoop water from this place.\n");
         /* syntax is ok, but not proper room */
       return 1;
      }
 return 0;
}



int pour(string str){
string where;

 notify_fail("Pour out what?\n");
 if (!is_water || !str) return 0;
 if (str=="out water"){
    write("You pour out the water from your bucket.\n");
    say(TP->query_name()+" pours out the water from a bucket.\n");
    is_water=0;
    return 1;
 }
 if (sscanf(str,"out %s",where)==1)
  if (where=="water in fire" || where=="water on fire"){
     if (file_name(environment(TP))==COTT){
        write("You pour the water on the fire.\n");
        write("You duse the fire.\n");
        say(TP->query_name()+" pours the water on the fire.\n");
        say(TP->query_name()+" douses the fire.\n");
        is_water=0;
        COTT->duse();
        return 1;
     } 
     write("You are not allowed to do it here.\n");
     return 1;
  }
 return 0;
}

