//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc= 
    "You are traveling on a countryside path in Pavi. "+
    "You notice paths lead in all directions with flowers "+
    "and bushes growing in spotted areas all throughout "+
    "the area.\n";
    dest_dir=({
               "players/dragonn/area/ctr20", "north",
               "players/dragonn/area/ctr25", "west",
               "players/dragonn/area/ctr27", "east",
               "players/dragonn/area/ctr30", "south",
             });

    items=({ 
            "paths","You are standing in the middle of a dirt trail. "+
                    "You notice flowers and bushes growing throughout "+
                    "the land",
            "bushes","You notice small bushes protruding from the ground",
            "flowers","You spot beautiful wild flowers growing amoung the "+
                      "sunshine",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
