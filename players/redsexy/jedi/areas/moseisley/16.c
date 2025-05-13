inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The western edge of the town square in Mos Eisley.";
  long_desc="You follow the square round and now stand outside a stone hut labelled "+
            "'Clothesmaker Clive's'.  The town wall to your west is shielding the sun "+
            "but you still feel hot and sticky as you venture onwards.\n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/3","northeast",
             "/players/redsexy/jedi/areas/moseisley/15","north",
           });
  
  items=({"path","The path is now paved with redbricks, hot and slightly cracked from the sun, yet still easy to travel on",
          "square","The square is surrounded by cabins built from stone, and you stand on the western edge",
          "hut","The hut to the north is labelled 'Clothesmaker Clive's.",
          "sun","The sun is fierce here, and the redbricks absorb a lot of the heat",
          "wall","Towering many feet above your head, the wall blocks the village from intruders",
         });

  ::reset();
   replace_program("/room/room");

}


