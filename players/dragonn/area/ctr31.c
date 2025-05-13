//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are standing in the middle of an intersection "+
    "of paths.  Many of the trails are lined with "+
    "beautiful wild flowers and very small shrubs. "+
    "You notice branches from large trees stretched "+
    "out above your head.\n";

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    dest_dir=({
               "players/dragonn/area/ctr27", "north",
               "players/dragonn/area/ctr30", "west",
               "players/dragonn/area/ctr34", "south",

             });

    items=({ 
      "intersection","You notice that you are standing in "+
               "the middle of a crossroads.  Paths lead in almost every "+
               "direction",
      "flowers","You notice wild flowers surrounding "+
                "most of the trails",
      "shrubs","You spot many small shrubs growing next to the paths",
      "branches","As you look up you see branches from a nearby oak tree "+
                 "stretching out above you",


          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
