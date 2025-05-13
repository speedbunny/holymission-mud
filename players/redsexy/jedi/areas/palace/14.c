inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A long hallway leading through Jabba's Palace.";     
        long_desc = "\
This long hallway stretches the full legnth of Jabba's palace, from the greeting \
hall to the storerooms.  The blue carpet is so soft to walk on, and the air is so \
refreshingly cool in here, you wonder why people always moan about the conditions \
that Jabba lives in.  The marble walls have many paintings hung on them, and you study \
the pictures as you venture along. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/7",  "south",
            "/players/redsexy/jedi/areas/palace/15", "north",

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
       });
    }
    ::reset(arg);
    replace_program("room/room");
}


