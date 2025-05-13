inherit "/room/room";
#define T this_player()

reset(arg){
 ::reset(arg);
 set_light(0);
 short_desc=("A dark cave");
 no_castle_flag=1;
 long_desc=("You are in the dark cave.\n"
            +"There is a small pitch lake here.\n");
 smell="You smell damp air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood38","out"});
 items=({"cave","The cave is damp and dark",
	 "dark cave","The cave is damp and dark",
	 "pitch","The hot dark pitch",
	 "hot pitch","The pitch is dark and hot",
	 "lake","It is a small pitch lake",
	 "pitch lake","It is a small pitch lake",
 	 "small pitch lake","It is a small pitch lake",
	 "dark pitch","The pitch is hot and dark",
	 "hot dark pitch","The pitch is dark and hot",
	 "dark hot pitch","The pitch is hot and dark",
	 "damp cave","The cave is damp and dark"});
 }
init(){
 ::init();
 add_action("dip","dip");
 }

int dip(string str){
object torch,stick,bottle;

  notify_fail("Dip what where ?\n");
  if (!str) return 0;
  if (str=="stick in pitch" || str=="stick in lake" || 
     str=="stick in pitch lake"){

   if (present("stick",T)){
       write("You dip the stick in the pitch and make a torch.\n");
       say(T->query_name()+" makes a torch.\n");
       stick=present("stick",T);
       torch=clone_object("/obj/torch");
       transfer(torch,T);
       destruct(stick);
   }
    else {
     write("But you don't have a stick !\n");
     say(T->query_name()+" grins.\n");
   }
  return 1;
 }
 if (str=="bottle in lake" || str=="bottle in pitch" || 
      str=="bottle in pitch lake"){
    if (present("special bottle",T)){
       bottle=present("special bottle",T);
       if (bottle->is_my_bottle()) bottle->add_pitch();
     }
    if (!present("bottle",T)){
     write("But you have no bottle !\n");
     return 1;
    }
    write("You dip "+str+".\n");
    say(T->query_name()+" dips "+str+".\n");
  return 1;
 } 
 
 return 0;   
 }

