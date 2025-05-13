inherit "/room/room";

reset(arg){
 if (!arg){
 set_light(1);
 short_desc=("Courtyard");
 long_desc="You are stand at the south end of Palace courtyard.\n"+
	   "The green grass and flowers looks well. The courtyard\n"+
	   "continues to the north. To the south and east is a stony\n"+
	   "wall and to the west residence of nottingham sheriff.\n";
 
 smell="You smell a fresh grassy air.";

 dest_dir=({ "/players/goldsun/nottingham/room/castle/court2","north" });

 items=({  "grass","The fresh grass looks well",
	   "flowers","The flowers looks very well",
           "green grass","Nice green grass is waving in the wind",
           "residence","It is the residence of nottingham sheriff",
           "wall","Stony castle wall",

        });

 }
 ::reset(arg);
 replace_program("room/room");
}

