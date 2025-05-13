//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
"You are walking through the beautiful countryside of Greece. \n"+
"From where you stand you can see beautiful green grass \n"+
"growing in the sunshine, it is sprinkled with wild flowers \n"+
"and small shrubs.\n";


    dest_dir=({
               "players/dragonn/area/ctr08", "south",
               "players/dragonn/area/ctr02", "east",
             });

    items=({ 
            "shrubs","You notice many small shrubs"+
                     " growing from the ground in the distance.\n",
            "grass","You notice beautiful green grass growing everywhere"+
                    " except for the trail you are standing on.\n",
            "pavi","You are standing in the beautiful countryside located "+
                   "in Pavi.\n",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
