inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,1,"sheriff","/players/goldsun/nottingham/monster/sheriff",0});
 set_light(1);
 short_desc=("Palace throne room");
 long_desc="Palace throne room. This is a large vaulted room.\n"+
        "Long tables line the walls, and there is a throne at the far\n"+
	"end of the room. Torches along the wall give off an odour of smoke.\n";
 
 smell="You smell torch smoke.";

 dest_dir=({ "/players/goldsun/nottingham/room/castle/tower1","north",
	     "/players/goldsun/nottingham/room/castle/hall1", "east",
  	     "/players/goldsun/nottingham/room/castle/weap","south" });

 items=({  "torches","They are attached to the wall",
    "residence","It is the residence of nottingham sheriff",
    "throne","The throne is made of ebony wood",
    "tables","They are by the walls. The tables are long and made of wood",

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

