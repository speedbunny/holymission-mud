inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A rowdy brothel";

  long_desc="You are still in the hallway of the brothel.  It seems rather " +
            "quiet here.  You can finally take some time to look at you " +
            "surroundings, rather than focusing on the interesting " +
            "characters which inhabit this house.  There is a really " +
            "beautiful chandelier overhead, and exotic plants along the " +
            "walls.  A rich blue carpet lines the hall, which continues to " +
            "to the east and west.\n";

  dest_dir=({"/players/emerald/town/bu4","east",
             "/players/emerald/town/bu7","west",
             "/players/emerald/town/bu1","south",
           });

  items=({"plants","Healthy, happy green plants",
          "carpet", "It looks quite expensive",
          "chandelier","A magnificent affair in crystal and gold",
        });

  ::reset(arg);
   replace_program("/room/room");

}
