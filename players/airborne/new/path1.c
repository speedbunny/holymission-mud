inherit "room/room";

reset(arg){
 if(!arg){

   set_light(0);
   short_desc = "Duegar path";
   long_desc = 
"The bushes give way to a small stone path leading to a cavern off in the "+
"distance. The greenery covers the path well leaving only hints of its "+
"existance to the north and south.\n";

   items = ({"bushes", "Cute little bushes",
	"path", "A small stone path almost completely covered with bushes",
	"cavern", "A small cavern off in the distance", });

   dest_dir = ({"players/airborne/new/park8", "north",
		"players/airborne/new/path2", "south", });

   smell = "A hint of greens mixed with a bit of musty dampness.";

replace_program("room/room");
    }
}
