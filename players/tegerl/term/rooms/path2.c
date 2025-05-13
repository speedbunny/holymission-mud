
inherit "room/room";
void reset(int arg)
{

if (!arg);
{
clone_list = ({ 1, random(4), "termite" ,"players/tegerl/term/monsters/termite" ,0 });
set_light(0);
short_desc="In a termites-hill";

long_desc=
    "Dark corridors leading here and there, small pieces of lumber, the rest " +
    "of the termites' meals can be seen everywhere.\n"; 

dest_dir=({
    "players/tegerl/term/rooms/path1", "south",
    "players/tegerl/term/rooms/path3","east",
    "players/tegerl/term/rooms/path4","west",
    "players/tegerl/term/rooms/path5","northeast",
    "players/tegerl/term/rooms/path6","northwest",
    "players/tegerl/term/rooms/path7","southwest",
    "players/tegerl/term/rooms/path8","southeast",

    });

items=({
    "forest","The forest is very dark, you wonder what creatures could live in it. You decide to stay away",
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "trails","As you look at the trails you think that maybe a carriage used this path",
    "trail","As you look at the trail you think that maybe a carriage used this path",
    "lumber","The rest of the termites' meals",
});


smell = "The air is damp and you can smell rotten trees.";
  
  }

::reset(arg);
replace_program("room/room");

}



