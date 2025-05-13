inherit "/room/room";
#define TP this_player()
#define PATH "/players/goldsun/green_island/room/"
#define OPN TP->query_name()

reset(arg){
if (arg) return;
 set_light(1);
 short_desc=("At the coast");
 long_desc=
  ("You are standing on the coast of Green Island. The ground\n"
  +"consists of sand with a strange sign. Huge waves are rolling\n"+
   "towards the island and you get a peacefull feeling. Further\n"+
   "from the coast you can see a very nice meadow.\n");
                

 smell="You smell fresh, damp and salt air.";

 dest_dir=({ PATH + "coast5", "northwest",
	     PATH + "meadow1","west",
	     PATH + "coast2"  , "southwest" });

 items=({"sea","The sea is blue",
	 "water","The water looks very clear",
    	 "coast",long_desc,
	 "island",long_desc,
         "sign","It is a magic circle painted on the sand. You see a footprint"+
          	" in it",
         "footprint","You see nothing strange on it",
 	 "ground","The ground consists of sand with a strange sign",
	 "sand","The sand is light yellow",
	 "light yellow sand","The sand is pleasant warm",
	 "warm sand","The sand is light yellow",
	 "wave","The huge wave is rolling towards the coast",
	 "huge wave","The wave is rolling towards the coast",
	 "waves","The huge waves are rolling towards the coast",
	 "huge waves","The waves are rolling towards the coast",
	 "meadow","It looks very nice from here"
         });
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("do_get","get");
  add_action("swim","swim");
  add_action("enter","enter");
  add_action("drink","drink");
  }

enter(arg){
  if (!arg) return;
  if (arg=="sea" || arg=="blue sea" || arg=="water") return  swim();
  if (arg=="circle" || arg=="magic circle"){
    write("As you enter magic circle you, magic force transfers you.\n");
    TP->move_player("in a puff of smoke#players/goldsun/green_island/hm_coast");
    return 1;
  }
  return 0;
}

int drink(string arg){
  if (!arg) return 0;
  if (arg=="water" || arg=="salt water" || arg=="clear water" ||
   	 arg=="clear salt water" || arg=="water from sea"){
   write("As you drink some salty water from the sea, you get a bad"
    +"feeling.\n");
   TP->add_poison(3);
   say(OPN+" drinks some water.\n");
   return 1;
   }
  }


 do_get(str){
  if (str=="sand"){
   write("The sand slips through your fingers.\n");
   say(OPN + "tries to take the sand.\n");
   return 1;
  }
 }

 lsten(){
      write("You can hear the sea waves.\n"); 
  return 1;
  }              

 swim(){
  write("You jump into the water and swim around for a while.\n");
  say(OPN+" jumps into the water and swims around for a while.\n");
  return 1;
 }
  
