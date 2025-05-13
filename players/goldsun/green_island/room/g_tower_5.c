inherit "/room/room";
#define OUT "/players/goldsun/green_island/room/outside_gates"

int rock;

void do_fall(){
 write("You push a boulder down from wall.\n");
 OUT->fall_stone();
 return;
}

reset(arg){
 rock=40+random(30);
if (!arg){
 set_light(1);
 short_desc=("On the top of gate-tower");
 long_desc="Top of the tall gate-tower. It is made of rock and looks very.\n"+
	   "sturdy. You have a nice view over sea and island. You can see\n"+
	   "many boulders here. Cyclops use them for defence of\n"+
	   "Rockland castle.\n";

 smell="You smell salt fresh air.";

 dest_dir=({"/players/goldsun/green_island/room/g_tower_4","down"});

 items=({"castle","A marble castle. It's named Rockland",
	 "sea","Waves are rolling toward the island",
	 "island","Green island",
	 "boulders","They are big and small, dark and light. You can push them",
         "boulder","A big dark rock. It looks very heavy. You can push it",
	 "tower",long_desc
         });
 }
 ::reset(arg);
}



init(){
 ::init();
add_action("push","push");
}

int push(string str){
 if ((str=="boulder" || str=="rock") && rock>0){
   rock--;
   tell_room(OUT,"A heavy boulder is falling down.\n");
   call_out("do_fall",3); 
   return 1;
   }
 return 0;
}

