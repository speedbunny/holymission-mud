inherit "/room/room";
#define TP this_player()

void reset(int arg){

if (!arg){
 set_light(1);
 short_desc=("Goldsun cottage");
 long_desc="You are in the Goldsun cottage. This is his resting cottage.\n"+
           "He is very often here.\n";
   
 smell="You smell nice wooden smell";

 hidden_dir=({ "/players/goldsun/nottingham/room/road10","east"});

  property=({"no_teleport"});
  items=({ "floor","A wooden floor is made of oak"
	  });
  }
 ::reset(arg);
 replace_program("room/room");
}

