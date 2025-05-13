inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A long hallway leading through Jabba's Palace.";     
        long_desc = "\
You have reached an intersection on the long corridor that stretches through the \
palace.  To the west you can smell food cooking, and to the east you can hear the \
sound of laughter.  The blue carpet continues to your north and south, but you are \
tempted to venture off the beaten path in search of greater adventure. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/16",  "south",
            "/players/redsexy/jedi/areas/palace/14",  "north",
            "/players/redsexy/jedi/areas/palace/5",   "west",
            "/players/redsexy/jedi/areas/palace/8",   "east",
        });


         items = ({
             "hallway", "A long hallway running through Jabba's palace",            
             "walls", "They seem to be made of marble, and various paintings \
hang on them",
             "paintings", "These mainly seem to be portraits of local dignitaries \
and family",       
             "pictures", "These mainly seem to be portraits of local dignitaries \
and family",       
             "floor", "The floor is carpeted in rich blue, and the carpet continues \
to the south",
             "carpet", "This carpet is a very royal blue, and unspoilt",
             "storerooms", "You can see the storerooms far to the south",
             "air", "The marble walls make the air in here cool, a refreshing change \
from the desert",
             "intersection","You can go east or west from here",
       });
    }
    ::reset(arg);
    replace_program("room/room");
}


