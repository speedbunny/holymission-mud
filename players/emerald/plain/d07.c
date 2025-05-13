inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="In the sand dunes";
  long_desc="The eastern ridge of dunes is not as high as its inland " +
            "counterparts.  They form a gentle slope to the wide sandy " +
            "beach which extends eastward towards the pounding waves of " +
            "the sea.  In the valley between the dunes, a profusion of " +
            "salt-loving plants grows in blissful peace.  Down at the base " +
            "of the grass, a small nest has been hidden.\n";


  dest_dir=({"/players/emerald/plain/d09","north",
             "/players/emerald/plain/d05","south",
             "/players/emerald/plain/b10","east",
             "/players/emerald/plain/d06","west",
             "/players/emerald/plain/b12","northeast",
             "/players/emerald/plain/d08","northwest",
             "/players/emerald/plain/b08","southeast",
             "/players/emerald/plain/d04","southwest",
           });

  items=({"ridge","A chain of sand dunes between the plain and the beach",
          "dunes","Large mounds of collected sand",
          "beach","A clean, wide, white sand beach",
          "counterparts","The dunes of the western ridge",
          "waves","Rolling, aquamarine waves breaking on the sand",
          "sea","It is a clear, inviting blue",
          "valley","A protected hollow between the sand dunes",
          "plants","A variety of extremely hardy, salt-tolerant plants",
          "base","The grass sprouts out of the sand at that point",
          "grass","A rather pervasive photosynthesizing lifeform",
          "nest","A bird nest",
        });

  clone_list=({
    1,1,"bird","obj/monster", ({
      "set_name","sand piper",
      "set_alias","piper",
      "set_alt_name","bird",
      "set_race","bird",
      "set_short","A sand piper",
      "set_long","A sand piper protecting its nest from intruders.\n",
      "set_level",7,
      "add_money",70,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
