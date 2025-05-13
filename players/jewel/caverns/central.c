inherit "room/room";

reset(arg){

  if (arg) return;
  set_light(1);
  short_desc = "Cavern with many exits";   
  long_desc = "In this cavern you have several directions you can take.  "+
    "Look everywhere to carefully choose your direction, your destiny.\n";
  dest_dir = ({"players/jewel/caverns/hard1", "northwest",
          "players/jewel/caverns/fun1", "west",
          "players/jewel/caverns/medi1", "southwest",
          "players/jewel/caverns/entrance", "east",
         });
  items = ({"floor","A limestone floor with worn tracks leading in "+
                  "several directions",
	"walls","The walls are glowing!\n It is brightest "+
		"in one concentrated area.\n Maybe you can dig to investigate",
	"wall","The wall is glowing!\n It is brightest in one concentrated area.\n Maybe you can dig to investigate",
	"ceiling","The ceiling is still hidden in the darkness",
	"northwest","As you look northwest down the dark cavern, "+
                "a cold, cold wind\n"+ 
		"chills you to your very bones.  Surely, death awaits you there",
	"west","As you look west down the well-lit cavern, "+
		"you feel completely at ease",
         "southwest","As you look sowthwest down the dark cavern, "+
		"you feel a challenging\nadventure awaits you",
          "east","As you look east, you realize this leads back to the sea.",
        });
}
 
init(){
 ::init();    
 add_action("make_gcrystal", "dig");     
}
 
make_gcrystal(arg){
    
object gcrystal;
 
  if((arg == "wall")||(arg == "at wall")){
    gcrystal = clone_object("players/jewel/caverns/objs/gcrystal");
    transfer(gcrystal, this_player());
    write("You find a glowing crystal!  Its light is "+
                "nearly blinding.\n");
    return 1;
    }
    write("What are you going to dig?\n");
    return 1; 
}

