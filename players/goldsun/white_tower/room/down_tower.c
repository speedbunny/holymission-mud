inherit "/room/room";
#define TP this_player()


void kick(object pl){
 if (living(pl) && !pl->query_npc()){
 write("God kicks you out of this tower.\n");
 TP->move_player("out#/room/church");
 return;
 }
}
   

reset(arg){

if (!arg){
 clone_list=({1,1,"dragon","players/goldsun/white_tower/monster/dragon",0});
 set_light(1);
 short_desc=("Tower cell");
 long_desc="You stand in the dump tower cell.\n";
   
 smell="You smell rotten air";
 no_obvious_msg="";
 property=({"no_teleport"});
 items=({ "cell",long_desc,
	  "tower",long_desc
	  });
  }
 ::reset(arg);

}

init(){
 ::init();
 call_out("kick",15,TP);
}

