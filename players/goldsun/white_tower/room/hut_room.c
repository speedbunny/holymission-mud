inherit "/room/room";

void reset(int arg){

if (!arg){
 clone_list=({1,1,"master","players/goldsun/white_tower/monster/master",0});
 set_light(1);
 short_desc=("In the hut");
 long_desc="You are inside small hut with a bed, a table and a chair.\n";
 smell="You smell mud and grass.";
 dest_dir=({ "/players/goldsun/white_tower/sforst_g","out"});
 property=({"no_teleport"});

  items=({ "bed","Oak board with haystack on it",
   	   "hut",long_desc,
 	   "table","New oak table",
	   "chair","It is made of oak"
	  });
  }
 ::reset(arg);
 replace_program("room/room");
}

