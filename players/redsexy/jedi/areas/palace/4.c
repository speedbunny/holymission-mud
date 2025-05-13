inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "The cold room of Jabba's Palace.";     
        long_desc = "\
This seems to be a cold room, for perishable goods that Jabba consumes.  Encapsulated \
in marble apart from the entrance, the temperature in here has to be almost freezing! \
You teeth chatter as you look around. \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/5",  "south",
            "/players/redsexy/jedi/areas/palace/2",  "north",

        });
 
        clone_list = ({
            1,1,"chef","obj/monster", ({
            "set_name","portly",
            "set_alt_name","chef",
            "set_long","Thisis Portly, Jabba's long suffering chef.\n",
            "set_race","human",
            "set_level",20,
            "set_gender",1,
            "set_wc",30,
            "set_ac",11,
    }),

           -1, 1, "jabba_1", "/obj/thing", ({
           "set_name", "A wooden key",
           "set_alias", "jabba_1",
           "set_alt_name", "key",
           "set_short", "A wooden key",
           "set_long", "A wooden key, crafted from oak.\n",
           "set_weight", 1,
    }),
});

         items = ({
             "room", "Thisis where the frozen foods are kept",            
             "food", "Everything is frozen and too cold to touch!",
             "marble", "White marble",       
             "temperature", "If you don't get out of here soon you'll freeze!",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}


