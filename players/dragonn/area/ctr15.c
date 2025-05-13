//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg);
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
   "You notice all the beautiful leaves falling "+
     "from the trees around you. There is a path "+
    "leading to the east and one into an opening "+
    "to the south. The trees are half bare due "+
    "to the wind blowing.\n"; 
move_object(clone_object("players/dragonn/area/esmeralda"),this_object());

    dest_dir=({
               "players/dragonn/area/ctr08", "north",
               "players/dragonn/area/ctr16", "east",
               "players/dragonn/area/ctr22", "south",
             });

    items=({ 
            "leaves","You notice all the leaves are different"+
                     " colors and sizes",
            "opening","You notice an opening in the path to your south."+
                      "You should possibly check it out",             
            "path","You notice a path full of leaves leading to the east",
   "trees","The talm elm trees are mostly bare of their leaves",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
