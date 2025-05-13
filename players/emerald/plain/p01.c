inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";

  long_desc="You are wading through waist-high grass on the edge of a " +
            "plain.  To the east lies the edge of the thick and " +
            "foreboding Ilkin Forest.  To the west lies the enchanted path " +
            "which will conduct you safely through this endless sea " +
            "of grass.\n";

  dest_dir=({"/players/emerald/plain/p02","north",
             "/players/emerald/plain/p03","northeast",
             "/players/kryll/rooms/path/ep12","west",
           });

  items=({"grass","Long grass heads bending in the breeze",
          "forest","The Ilkin forest is thick and rumoured to contain fairies "+
                   "and other evil spirits",
          "plain","A desolate span of waving grass",
        });

  ::reset();
  replace_program("/room/room");

}
