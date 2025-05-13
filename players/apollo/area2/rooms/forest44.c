

inherit "room/room";

object bear;
object ant;

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
        "players/apollo/area2/rooms/shore38", "south",
        "players/apollo/area2/rooms/forest43", "west",
        "players/apollo/area2/rooms/forest39", "southeast",
        "players/apollo/area2/rooms/shore37", "southwest",
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"ground", "The ground is covered in old brown pine needles",
	});

  smell = "You smell the fresh fragrance of pine needles";

  move_object((clone_object("players/apollo/area2/monsters/bear")),
	this_object());
  move_object((clone_object("players/apollo/area2/monsters/ant")),
	this_object());

}


