inherit "/room/room";

reset(arg){
 if (!arg){
 clone_list=({1,1,"leila","/players/goldsun/nottingham/monster/leila",0});
 set_light(1);
 short_desc=("Bedroom");

 long_desc="You are in the bedroom. There is a big bed in the middle\n"+
	   "of the room. You can see high candlesticks in the corners\n"+
	   "and large window on the north wall.\n";
 
 smell="You smell pleasant odour";

 dest_dir=({"/players/goldsun/nottingham/room/castle/private","south"});

 items=({ "bed","It is large and made of wood",
	  "candlesticks","They are in the corners",	
	  "candlestick","There is a candle on it",
	  "candle","It is not lighted",
	  "window","A large window on the north wall"
        });

 }
 ::reset(arg);
 replace_program("/room/room");
}

