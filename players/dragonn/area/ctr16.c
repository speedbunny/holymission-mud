//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
"You are traveling on a east-west path."+
    "You notice a path leading north and a line "+
    "of shrubs to the south.  There are beautiful "+
    "wild flowers dotting the landscape.\n";

    dest_dir=({
               "players/dragonn/area/ctr15", "west",
               "players/dragonn/area/ctr09", "north",
               "players/dragonn/area/ctr17", "east",
             });

    items=({ 
            "leaves","You notice all the leaves are different"+
                     " colors and sizes",
            "opening","You notice an opening in the path to your south."+
                      "You should possibly check it out",             
  "path","You are standing in the middle of a dirt trail. "+
                   "You notice vegetation growing on both sides of it",
     "shrubs","You notice a line of shrubs."+
                     "It could be someplace important",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
