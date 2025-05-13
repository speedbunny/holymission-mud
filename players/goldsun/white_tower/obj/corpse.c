inherit "/obj/corpse";
#define TP this_player()

void long(){ write("The dead body of White-Tower guard.\n"); }

decay()
{
	return;
}


void  reset(int arg){
  ::reset(arg);
 if (arg) return;
 set_name("guard");
 set_race("dwarf");
 weight=9;
 }


init(){
 ::init();
add_action("bury","bury");
}

int bury(string str){
string place, *placetest; 

  notify_fail("Bury what?\n");
  if (str=="corpse"){ 
    place = file_name(environment(TP));
    placetest = explode(place,"/");
    if(placetest[1] == "goldsun" && placetest[2] == "white_tower") {
     write("You bury a corpse of guard.\n");
     write("Ring appears out of nowhere.\n");
     move_object(clone_object("players/goldsun/white_tower/obj/ring3"),
	   environment(TP));
     say(TP->query_name()+" buries a corpse.\n");
     say("Ring appears out of nowhere.\n");
     destruct(this_object());
     return 1;
     }
     write("You bury a corpse of guard.\n");
     say(TP->query_name()+" buries a corpse.\n");
     destruct(this_object());
     return 1;
   }
}


