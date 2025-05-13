//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "This place is covered with many flowers "+
    "and many different types of shrubs all "+
    "around you.  There are beautiful trees "+
    "towering all above you.  There are three "+
    "paths here to choose from.\n";


    dest_dir=({
               "players/dragonn/area/ctr31", "north",
               "players/dragonn/area/ctr33", "west",
               "players/dragonn/area/ctr38", "south",

             });

    items=({ 

      "flowers","You notice wild flowers surrounding you",
      "shrubs","You spot many different types of shrubs covering "+
        "the area around you",
      "trees","You see branches from nearby trees stretching out "+
        "above you",
      "paths","You are standing on a dirt path.  Many other paths "+
        "branch off into other directions",

          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
