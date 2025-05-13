//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "As you glance around you notice how beautiful "+
    "the countryside of Pavi really is.  You notice "+
    "wild flowers dotting the gorgeous landscape.  You spot some "+
    "leaves falling from nearby trees.\n";

    dest_dir=({
               "players/dragonn/area/ctr03", "west",
               "players/dragonn/area/ctr05", "east",
               "players/dragonn/area/ctr11", "south",
             });

    items=({ 
               "flower","A beautiful flower.\n",
            "flowers","You spot bunches of wild flowers sprinkled "+
                      "throughout the countryside",
            "path","You are standing on a dirt path",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
