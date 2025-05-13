
/* The generic "maze room object", to be inherited from the rooms in the maze. */

// whisky : 22.02.95 put to room.c 

inherit "/room/room";

string north_room, south_room, west_room, east_room;

MAZE_ROOM()
{
   return ({0,0,0,0});
}

reset(arg) 
{
    if (arg)
	return;
    set_light(1);
    no_obvious_msg = "";
    short_desc = "In the Mirror Maze";
    long_desc = break_text(
    "You are in the mirrormaze that was made by Uglagrok the mirrormage. " +
	      "The walls are covered with mirrors, and everything seems " +
	      "strangely reversed. "+
	      "It could be very easy to get lost in this place, " +
	      "especially with all those reversed directions...",60)+"\n";
    build_up_dirs();
    items =
    ({
     "mirror",
              "A large mirror covering the wall.\n" +
	      "You wouldn't be surprised if this is a magic mirror",
     "mirrors",
              "A large mirror covering the wall.\n" +
	      "You wouldn't be surprised if this is a magic mirror",
    });
} /* reset */

build_up_dirs()
{
   mixed dirs;

    if (!sizeof(dest_dir))
         dest_dir = ({});

    dirs = MAZE_ROOM();

    north_room = dirs[0];
    south_room = dirs[1];
    east_room = dirs[2];
    west_room = dirs[3];
    if (north_room)
    {
	dest_dir = dest_dir + 
        ({"players/padrone/maze/" + north_room,"north"});
    }
    if (south_room)
    {
	dest_dir = dest_dir + 
	({"players/padrone/maze/" + south_room,"south"});
    }
    if (east_room)
    {
	dest_dir = dest_dir + 
	({"players/padrone/maze/" + east_room,"east"});
    }
    if (west_room)
    {
	dest_dir = dest_dir + 
	({"players/padrone/maze/" + west_room,"west"});
    }
}
