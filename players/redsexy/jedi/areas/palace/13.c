inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);

        short_desc = "An entertainment room in Jabba's palace";     
        long_desc = "\
This is an entertainment room in the palace, where Jabba and his followers come to see \
music and performers from all over the realms.  The floor is made of black wood, ideal \
for dancing on, and a number of seats line the outside of the room, making it possible \
for many people to enjoy the acts bought in for Jabba's amusement.\n\n";

        dest_dir = ({
            "/players/redsexy/jedi/areas/palace/12",  "north",
        });


         items = ({
             "floor", "The floor is made of black wood, ideal for dancing",            
             "seats", "The seats line the outside of the room, for anyone \
who would dare to sit through an act with Jabba the Hut",
             "room",  "A room where bands and comedians come to perform in front of Jabba",
        });
    }
      clone_list=({
          1,2,"whore","obj/monster", ({
          "set_name","whore",
          "set_long","A tarty whore in a fit of uncontrollable giggles.\n",
          "set_race","whore",
          "set_level",20,
          "set_gender",2,
          "set_wc",30,
          "set_ac",11,
    }),
          2,2,"whipid","obj/monster", ({
          "set_name","whipid",
          "set_race", "whipid",
          "set_long","A long-snouted, grey skinned whipid.\n",
          "set_level",20,
          "set_ac",10,
          "set_wc",8,
          "set_gender",1,
    }),
          3, 1, "salacious", "/players/redsexy/jedi/monsters/salacious", 0,

  });

    ::reset(arg);
    replace_program("room/room");
}


