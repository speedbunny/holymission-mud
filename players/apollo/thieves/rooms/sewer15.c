

inherit "room/room";

reset(arg)
{        
        if(arg) return;
        set_light(0);

short_desc = "A small sewer running under Holy Mission";

long_desc = 
	"You have entered an immense sewer system tunneling deep under \n" +
	"the main streets and paths of Holy Mission. As you look around \n" +
	"you see many decomposed skeletons of animals and people that did \n" + 
	"not make it out of the sewers alive. You can even make out small \n" +
	"rats scurrying around feasting on whatever fallen prey they can \n" +
	"find and laying on top of pipes. \n";

dest_dir = ({
        "players/apollo/thieves/rooms/sewer16", "east",
        "players/apollo/thieves/rooms/sewer14", "west",
           }); 

items = ({
	"air", "The air is full of an awful stench",
	"skeletons", "You see a slightly decomposed body of an animal",
	"pipes", "Running along the ceiling you see old pipes",
        "sewer", "You are walking through an old sewer",
	});

smell = "You smell decomposed flesh from dead corpses";
  
}


