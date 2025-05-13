inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A long hallway down the eastern wing of Jabba's Palace.";     
        long_desc = "\
This hallway runs across the southern wing of Jabba's Palace, and a stairway in \
the corner leads upwards.  The red carpet here is still bloodsoaked from a recent \
battle and you fear what may lie ahead if you continued to explore this place. \
Heads, still oozing gore and brains are haphazardly nailed to the walls, and \
the whole place stinks of death. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/25",  "up",
            "/players/redsexy/jedi/areas/palace/17",  "west",
        });


         items = ({
             "gore", "Green,putrid,sickly gore",  
             "brains", "Pink,slimy,blood soaked brains",  
             "hallway", "A hallway running across the southern wing of the palace",            
             "walls", "Severed heads line the walls", 
             "heads", "Severed heads of adventurer's who displeased Jabba", 
             "floor", "The floor is carpeted in a bloodstained red, and the carpet continues \
to the east",
             "carpet", "This carpet is red and bloodstained",
       });
    }
    ::reset(arg);
    replace_program("room/room");
}


