inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(0);
  short_desc = "Underground river bank";
  long_desc = "You barely manage to squeeze into this cavern. The "+
	"cavern is bathed in a reddish hue that is given off by the "+
	"crystals here. Upon walking deeper west in the cavern, your feet "+
	"get wet from river water soaking them.\n";
  items = ({ "river", "An underground river. Its waters are very calm and peaceful",
	"cavern", "A small cavern squeezing down on you",
	"reddish hue", "A warm red glow given off by the red crystals embedded in the cavern as your light source falls upon them",
        "feet", "They are wet",
        "ground", "Smooth limestone ground.  It feels very slick",
        "crystals", "Small reddish crystals that peek out of the cavern walls",
            });
  dest_dir = ({ "players/jewel/caverns/fun5", "east",
		"players/jewel/caverns/fun7", "west", });
}
init(){
::init();

add_action("go_west", "west");
}
go_west(){
write("You slip and fall into the river!\n");
this_player()->move_player("into the river#players/jewel/caverns/fun7");
return 1;
}
