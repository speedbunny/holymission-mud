inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A side street";

  long_desc="The street has lost its quiet appeal.  From the north comes " +
            "the sound of scuffling and laughing, and from the south are " +
            "some truly horrific screams.  You hesitate to investigate the " +
            "origins of those sounds.  From this point you can see a large " +
            "house at the east end of the street.\n";

  dest_dir=({"/players/emerald/town/t17","east",
             "/players/emerald/town/t15","west",
             "/players/emerald/town/pub","north",
             "/players/emerald/town/barber","south",
           });

  items=({"house","A rather large house.  There's not much else to tell",
          "street","A small side street",
  });

  ::reset(arg);
   replace_program("/room/room");

}
