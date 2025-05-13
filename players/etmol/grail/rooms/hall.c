#define TP this_player()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(1); 
short_desc = "Hall"; 
long_desc = "You are standing in a huge underground room inside\n"+
           "the mountain. In the scarce light you don't see where the\n"+
           "ceiling is as you look up but you suspect it is very high\n"+
           "above you. You hear the sound of water dripping and\n"+
           "echoing all around you.\n"+
           "A narrow path leads deeper into the mountain to the east\n"+
           "and another one leading north disappears into the darkness.\n",           

items = ({
          "entrance", "Must have been a lot of work.",
          "rock", "Old, crumbling rock.",
          "wall", "Old, crumbling rock.",
          "walls", "Old, crumbling rock."
});
dest_dir = ({
             "/players/etmol/grail/rooms/temple2", "east",
             "/players/etmol/grail/rooms/dragon1", "north"
});
}
