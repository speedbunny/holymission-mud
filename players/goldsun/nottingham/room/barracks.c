inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,5,"soldier","players/goldsun/nottingham/monster/soldier",0,
	      2,1,"guard","players/goldsun/nottingham/monster/upper_g",0});
 set_light(1);
 short_desc=("Barracks");
 long_desc=
    "You are in the Nottingham barracks. Guards are waiting here for\n"+
    "their missions. Fireplace in the cornener, tables witch chairs and\n"+
    "torches  make this place more pleasantly.\n"; 

 property=({"has_fire"});
 smell="You smell smoke of torches.";

 dest_dir=({ "/players/goldsun/nottingham/room/road13","west" });

 items=({  "torches","They are fixed to the wall",
	   "fireplace","It is made of stone. There is nice fire in it",
	   "tables","They are made of oak. Some of them are very dirty",

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

