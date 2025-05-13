inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain at the edge of the forest";


  long_desc="You are at the edge of a grassy plain, surrounded on three " +
           "sides by the dark and forbidding Ilkin Forest.  The trees " +
           "grow thickly along the edge of the forest, blocking any " +
           "entrance into it from this area.  To the west, the grassland " +
           "continues.\n";

  dest_dir=({"/players/emerald/plain/p02","west",
            "/players/emerald/plain/p01","southwest",
          });
  items=({"plain","A flat area of grassland",
          "forest","It is rumoured to be quite dangerous",
          "trees","They are tall and dark",
          "grassland","A flat area of waving grass",
        });

  ::reset();
  replace_program("/room/room");

}
