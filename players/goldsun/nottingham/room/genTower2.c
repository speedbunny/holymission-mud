inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,1,"guard","/players/goldsun/nottingham/monster/sleep_guard",0});
 set_light(1);
 long_desc="You are on the watch tower. It is small and made of stone.\n"+
	   "You have a nice view from this place. The stairs by the wall\n"+
           "leads down.\n";

 smell="You smell drunkards in the air.";


 items=({  "tower","It is made of stone",
           "stairs","Wooden stairs. They leads down",
	   "view","You can see forest and town from here",
           "town","It is Nottingham",
	   "forest","A green forest. It seems you see some orcs in it"

        });

 }
 ::reset(arg);
}

