

inherit "room/room";

object worm;

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
        "players/apollo/area2/rooms/shore31", "south",
        "players/apollo/area2/rooms/shore38", "west",
        "players/apollo/area2/rooms/forest45", "northeast",
        "players/apollo/area2/rooms/forest32", "southeast",
        "players/apollo/area2/rooms/forest44", "northwest"
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"ground", "The ground is covered in old brown pine needles",
	});

  smell = "You smell the fresh fragrance of pine needles";

  move_object((clone_object("players/apollo/area2/monsters/worm")),
	this_object());

}


