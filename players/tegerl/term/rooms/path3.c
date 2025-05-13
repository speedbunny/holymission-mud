
inherit "room/room";
void reset(int arg)
{

if (!arg);
{
clone_list = ({ 1, random(4), "termite" ,"players/tegerl/term/monsters/termite" ,0 });
set_light(0);
short_desc="In a termites-hill";

long_desc=
    "Endless tunnels, your aggressions against those termites rage high, " +
    "not enough that they destroy all buildings, now it seems that you " +
    "can't find out of here too.\n ";

dest_dir=({
    "players/tegerl/term/rooms/path1", "east",
    "players/tegerl/term/rooms/path2","north",
    "players/tegerl/term/rooms/path4","west",
    "players/tegerl/term/rooms/path5","northeast",
    "players/tegerl/term/rooms/path6","northwest",
    "players/tegerl/term/rooms/path7","southwest",
    "players/tegerl/term/rooms/path8","southeast",

    });

items=({
    "path","The ground is muddy and you can see that it has been used lately",
    "footprints","Yes, footprints, and they are human",
    "trails","As you look at the trails you think that maybe a carriage used this path",
    "trail","As you look at the trail you think that maybe a carriage used this path",
});


smell = "The air is damp and you can smell rotten trees.";
  
  }

::reset(arg);
replace_program("room/room");

}



