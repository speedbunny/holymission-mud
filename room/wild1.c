inherit "room/room";

void reset(int arg) {

    set_light (1);

    short_desc="In the wilderness";

    long_desc=
              "You are on a road leading west into a forest and " +
              "east into the village. To the south many cartwheels " +
              "have broadened a path through the thicket along " +
              "the river, to the north the view is barred by high " +
              "grass and bushes.\n";
    
    items = ({
              "river", "A peaceful river flowing from the north",
              "path", "It shows tracks of cartwheels and is " +
                      "covered by many kernels of corn",
              "road", "A well travelled road leading east-west " +
                      "from a village into a forest",
              "grass", "High grass which has not been cut for ages",
              "thicket", "It is too dense to break through it " +
                         "to reach the river",
              "bushes", "High bushes bar the sight of whatever " +
                        "might be in the north",
            }); 
       
    dest_dir = ({
                 "room/forest1","west",
                 "room/hump","east",
                 "players/whisky/mill_quest/path4","south",
                 "players/colossus/mearth/tree1","north",
               });

    ::reset(arg);
    replace_program("room/room");
}

