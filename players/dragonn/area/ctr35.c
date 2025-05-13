//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "Inside a Log House";
    long_desc=
      "You have just stepped inside of the log house. "+
      "It could have been your worse move yet because "+
      "there are tables overturned and clay dishes broken "+
      "all around you.  You notice a painting hanging on "+
      "the wall, it's a miracle that this is the only item "+
      "still in perfect condition.\n";


    dest_dir=({
               "players/dragonn/area/ctr36", "east",
             });

    items=({ 

       "painting","You are looking at a painting of the Lord " +
                  "Kaido",
       "tables","You notice that there are two wooden tables overturned "+
                "in the middle of the room",
       "dishes","You notice many dishes that lay broken on the " +
               "floor",

          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
