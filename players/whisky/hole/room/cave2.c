inherit "room/room";
#include "/players/gambit/defs2.h"
#include "/players/gambit/filter_live.h"

void reset (int flag)
{
    if (flag == 0 || (filter_live(this_object()) < 1) )
	move_object(clone_object("/players/whisky/hole/monster/demon"),this_object());
    if (flag == 0)
    {
	short_desc = "Danger Room";
	long_desc = 
          "This room looks like it was once a laboratory for the castle. "+
          "The whole place is in shambles, with chairs and tables thrown "+
          "about. Magical bottles are smashed and weapons are "+
             "shattered into pieces. Skeletons are all over the place "+
          "with a few bones missing. A large glass coffin sits against the "+
          "wall with tubes and hoses coming out of it. You notice "+
          "blood and scratches all over the coffin. It would "+
          "appear that a massacre occured here.\n";
	(BS("This room looks like it used to be a labratory for the castle. "+
	    "The whole place is in a shamble with chairs and tables thrown "+
	    "about. Magical bottles are smashed and weapons are shattered into "+
	    "pieces. Skeletons are all over the place, with a few bones missing. "+
	    "A large glass coffin sits standing up against the wall with tubes and "+
	    "hoses coming out of it. Huge scratches and blood cover the container. "+
	    "It looks like a massacre has happened here with all the blood splashed about."));
	dest_dir = ({
	  "/players/whisky/hole/room/cave1","south",
	});
	smell = "A foul smell of blood and body parts fill the room";
	items = ({
	  "wall","Huge scratches are dug into the wall",
	  "walls","Dried blood and scratches are dug into the wall",
	  "floor",
	  "Dried blood covers the floor",
	  "scratches","Huge scratches from something are dug into the walls",
	});
    }
}
