inherit "room/room";

reset(arg){

   set_light(1);
  
   dest_dir = ({"players/airborne/temple/entrance/land2", "east",
	"players/airborne/temple/entrance/bridge3", "south",
	"players/airborne/temple/entrance/land4", "west", });
  
  short_desc = "Lizardmen camping area";
  
  long_desc = "Lizardman seem to have made this area their campgrounds."
              "There are signs of long standing campfires and other such trash"
	      "about.\n";
  
  clone_list = ({ 1, 6, "lizardman", 
	"players/airborne/monsters/lizardman", 0 });

  ::reset();
  replace_program("room/room");	

}
