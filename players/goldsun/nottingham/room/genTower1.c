inherit "/room/room";

reset(arg){

 if (!arg){
 clone_list=({1,1,"guard","/players/goldsun/nottingham/monster/tower_guard",0});
 set_light(1);
 long_desc="You are inside the watch tower. It is small\n"+
           "and made of stone. The stairs by the wall leads up.\n";

 smell="You smell drunkards in the air.";


 items=({  "tower","It is made of stone",
           "stairs","Wooden stairs. They leads up"

        });

 }
 ::reset();
}

