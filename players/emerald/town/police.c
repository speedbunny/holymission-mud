inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The police station";

  long_desc="As you may have suspected on your journey down the street, you " +
            "have arrived at the police station.  You know this from the " +
            "high number of uniformed men lounging around behind desks, " +
            "trying to look official and in charge.  You also see large " +
            "crumbs from some sort of a breadlike object; one that was once " +
            "covered in powdered sugar.\n";

  dest_dir=({"/players/emerald/town/t4","west",
           });

  items=({"desks","Large wooden desks, behind which the police hide from work",
          "station","The headquarters of the town police",
          "crumbs","Whatever they were once a part of must have been tasty",
  });

  clone_list=({
    1,7,"policeman","obj/monster", ({
      "set_name","policeman",
      "set_race","human",
      "set_alias","police",
      "set_short","A nosy policeman",
      "set_long","This guy is out looking for trouble, his own, mainly.\n",
      "set_level",35,
      "set_wc",15,
      "set_gender",1,
    }),
  });

  ::reset(arg);
   replace_program("/room/room");

}
