inherit "/room/room";
object excalibur;

reset(arg){

 if (!arg){
 
 set_light(1);
 short_desc="Castle library";
 long_desc=
   "You are in the Carmaalot library. There are many bookshelves.\n";

 property=({"no_steal","no_fight"});

 smell="You can smell dusty air";

 dest_dir=({ "/players/goldsun/guild/room/treasury","down"});

 items=({"walls","The walls are made of shiny stone",
	 "wall","The wall is made of shiny stone",
	 "stone","Very nice white shiny stone",
	 "shiny stone","Very nice white shiny stone",
	 "stairs","The stairs leads down"
	 "bookshelf","The bookshelf is full of books",
	 "books","There are many books. They looks very old",
	 "bookshelves","The bookshelves are full of books"
       });

  }
 ::reset();
 replace_program("room/room");
}
