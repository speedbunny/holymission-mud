
// recoded it room/room : 22.02.95 whisky uni-linz.ac.at

inherit "/room/room";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
	set_light(1);
        short_desc = "A dimly lit forest";
        long_desc = break_text(
       "You are in part of a dimly lit forest. There are trees all around you. "+
	"Trails lead south and east, and a narrow path leads off to the west.",
        60)+"\n"; 
        items =
        ({
          "trees","You can't see the forest because there are so many of them",
        });
        dest_dir = 
        ({
            "room/south/sforst25","south",
            "room/south/sforst23","east",
            "players/whisky/quest/room/ravine1","west",
        });
    }
}

