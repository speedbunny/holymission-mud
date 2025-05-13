inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,1,"evil nottingham witch",
       "/players/goldsun/nottingham/monster/witch",0});
 set_light(1);
 short_desc=("Top of the tower");
 long_desc="You are in the top of the tower. This room is very dusty.\n"+
	   "There are many books and papers on the table. This is the\n"+
	   "workroom of the nottingham evil witch.\n";
 
 smell="You smell terrible odour.";
 dest_dir=({"/players/goldsun/nottingham/room/castle/tower3","down"});

 items=({ "stairs" ,"The stairs lead down",
	  "books","Dusty and old books on the table",
	  "papers","Dusty papers on the table"
	  	  
        });

 }
 ::reset(arg);
 replace_program("/room/room");
}

