inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "A work area in Jabba's palace.";     
        long_desc = "\
Wooden bowls filled with water and crockery are placed around the floor  Obviously \
this area is where everything gets cleaned up after one of Jabba's banquets.  The floor is \
still slippery with soap suds, and you watch your step to make sure you don't fall over. \
 \n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/3",  "north",
            "/players/redsexy/jedi/areas/palace/5",  "east",

        });

        property = ({"has_water"});

        clone_list = ({
            1, 1,"chef","obj/monster", ({
             "set_name","washer woman",
             "set_alt_name","woman",
             "set_race","human",
             "set_long","A washer woman cleaning the dishes and bowls.\n",
             "set_level",10,
             "set_ac",3,
             "set_wc",12,
             "set_gender",2,
             "set_al",500,
    }),

           -1, 1, "cloth", "/obj/thing", ({
             "set_name","washing cloth",
             "set_short","A cloth",
             "set_long","A wet cloth used for cleaning dishes.\n",
             "set_value",20,
             "set_alias","cloth",
    }),

           -1, 1,"bowl","players/redsexy/jedi/objects/bowl",0,
});

         items = ({
             "floor", "The floor is covered in tiles",            
             "tiles", "The tiles are slippery underfoot due to the soap suds.",
             "suds", "Soapy suds bubble into the air and drift around making you \
sneeze",       
             "bowls", "Wooden bowls filled with water",
             "water","Dirty soapy water with dirty dishes in it",
             "crockery", "Dirty dishes and plates",
        });
    }
    ::reset(arg);
    replace_program("room/room");
}

