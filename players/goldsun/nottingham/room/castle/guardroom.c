inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,2,"guard","players/goldsun/nottingham/monster/guard",0});
 set_light(1);
 short_desc=("Guardroom");
 long_desc="Palace Guardroom. This is the room where soldiers can spend their\n"+
	   "free time when they are waiting for their missions. There are\n"+
 	   "several tables with many chairs, torches on the wall\n"+
	   "and a fireplace in the corner.\n";


 property=({"has_fire"});
 smell="You smell smoke of torches.";

 dest_dir=({ "/players/goldsun/nottingham/room/castle/hall1","south" });

 items=({  "torches","They are fixed to the wall",
	   "fireplace","It is made of stone. There is nice fire in it",
	   "tables","They are made of oak. Some of them are very dirty",

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

