inherit "/room/room";
#define TP this_player()


void where_go(object pl){
  int al;

  if (!present(pl,this_object())) return;

  al=pl->query_alignment();
  if (al>200){
     write("You feel a magic force lifts you.\n");
     TP->move_player("up#players/goldsun/white_tower/room/up_tower");
     return;
   }
   if (al<-1000){
      write("You feel you are going down.\n");
      TP->move_player("down#players/goldsun/white_tower/room/down_tower");
      return;
   }
   write("You feel a present of magic force.\n");
}
   

reset(arg){

if (!arg){

 set_light(1);
 short_desc=("Inside a tower");
 long_desc=
   "You stand in the white tower. You cannot see anything beacause there\n"+
   "is a thick fog.\n";
   
 smell="The air smells lovely here";

 dest_dir=({ "/players/goldsun/white_tower/room/moon_place",   "out"});

 property=({"no_teleport"});

 items=({ "fog","It is very thick",
	  "tower",long_desc
	  });
  }
 ::reset(arg);

}

init(){
 ::init();
 call_out("where_go",5,TP);
}

