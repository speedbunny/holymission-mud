inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Trog village";
   long_desc = 
"You are in another small house. It looks as if it has been vacated.\n";

   dest_dir = ({"players/airborne/new/town13", "north", });
 
replace_program("room/room");
	
	}
}   
