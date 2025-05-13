inherit "/room/room";

#define TP this_player()
#define TO this_object()
#define TPN TP->query_name()
#define GATES "/players/goldsun/green_island/room/outside_gates"
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("Behind the gates");
 long_desc=
   ("You are standing under the gate tower. The ground is covered in glated\n"+
    "rocks. There are gates to the east and small stairs by the wall.\n");


 smell="You smell rotten air.";

 dest_dir=({ PATH + "courtyard1", "west",
	     PATH + "g_tower_2",  "up"});

 items=({"castle","White sturdy castle. It is made of stone",
	 "courtyard","@@long_desc@@",
	 "gates","@@query_gates@@",
	 "stairs","They lead up to the tower",
         "tower","A tall gate tower" 
         });
 }
 ::reset(arg);
}

string query_gates(){
 if (GATES->query_is_broken()) return "The gates are broken";
 return "The gates look very sturdy. There is no way to open them";
}

init(){
 ::init();
add_action("enter","enter");
add_action("open","open");
}

int open(string str){
 notify_fail("Open what ?\n");
 if (!str) return 0;
 if (str=="gates"){
   if (GATES->query_is_broken()){
       write("The gates are broken, you can pass.\n");
       return 1;
   } 
   if (TP->query_ghost()){
      write("You are a ghost. You pass through it.\n");
      TP->move_player("through the gates#/players/goldsun/green_island/room/outside_gates");
      return 1;
   }
   if (present("goldsun_bone_key_2010",TP)){
      write("Your key moves you through the gates.\n");
      TP->move_player("out#players/goldsun/green_island/room/outside_gates");
      return 1;
   }
   write("As you try to open it, a flash of lightning hits you!\n");
   TP->hit_player(5);
   say(TPN+" tries to open the gates and flash of lightning hits "+
            TP->query_objective()+".\n");
   return 1;
 }
 return 0;
}  

int enter(string str){
 if (str=="gates" || str=="castle"){
    if (GATES->query_is_broken()) 
      TP->move_player("out#/players/goldsun/green_island/room/outside_gates");
    else write("You bang your head against the gates.\n");
    return 1;
 }
 notify_fail("Enter what ?\n");
 return 0;
}
