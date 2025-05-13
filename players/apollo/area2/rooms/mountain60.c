

inherit "room/room";

object guard;

reset(arg){        
  if(arg) return;
  set_light(1);

  short_desc = "The base of a mountain";

  long_desc =
	"This is the dark forest. You begin thinking of what draws you to \n" +
	"explore a forest that appears to be so peaceful. This urges you to \n" +
	"explore it further. You see large trees around you, the ground is \n" +
	"covered in something, and the is a sweet smell in the air. You see \n" +
	"a large mountain rising higher above the trees as you go further to \n" +
	"the north. \n";

  dest_dir = ({
        "players/gareth/evil/cave/entcave", "north",
        "players/apollo/area2/rooms/mountain46", "south",
           }); 

  items = ({
	"mountain", "You see a large mountain rising above you to the north \n" +
	"forest", "You see large green pine trees all around you",
	"ground", "The ground is covered in old brown pine needles",
	});

  smell = "You smell the fressh fragrance of pine needles";

/*
  move_object((clone_object("players/apollo/area2/monsters/guard")),
	this_object());

*/
}


