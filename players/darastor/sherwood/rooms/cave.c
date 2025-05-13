inherit "/room/room";

void reset(int arg)
{
    ::reset(arg);
    no_castle_flag=1;
    
    set_light(0);
    short_desc=("A dark cave");
    long_desc=("You are in a dark cave, with damp, stone walls. There is a "+
      "distinctive scent here, and the atmosphere is very oppressive. This "+
      "does not strike you as somewhere you would like to stay for a long "+
      "time.\n");
    smell="A musty damp smell. The air here is not good.";
      
    dest_dir = ({
      "/players/goldsun/sherwood/room/Robin","out"
    });
    
    items = ({
      "cave","The cave is damp and dark",
      "dark cave","The cave is damp and dark",
      "damp cave","The cave is damp and dark",
      "walls","The cave walls are damp stone",
      "stone","The stone walls of the cave are all around you",
      "cave walls","The stone walls of the cave are all around you",
      "stone walls","The stone walls of the cave are all around you"
    });
    
    replace_program("room/room");
}
