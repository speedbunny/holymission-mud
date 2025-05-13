

inherit "room/room";

reset(arg){        
  if(arg) return;
  set_light(1);

  short_desc = "A deep thick forest";

  long_desc = 
	"This is the dark forest. You begin thinking of what draws you to \n" +
	"explore a forest that appears to be so peaceful. This urges you to \n" +
	"explore it further. You see large trees around you, the ground is \n" +
	"covered in something, and there is a sweet smell in the air. \n";

  dest_dir = ({
        "players/apollo/area2/rooms/forest34", "south",
        "players/apollo/area2/rooms/forest40", "west",
        "players/apollo/area2/rooms/forest35", "southeast",
        "players/apollo/area2/rooms/forest33", "southwest",
        "players/apollo/area2/rooms/mountain46", "northwest"
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"ground", "The ground is covered in old brown pine needles",
	});

  smell = "You smell the fresh fragrance of pine needles";

  clone_list = ({ 1, 3, "bear", "players/apollo/area2/monsters/bear", 0, });

  ::reset(arg);

}


