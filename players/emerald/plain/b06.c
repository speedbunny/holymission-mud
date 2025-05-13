inherit "/room/room";

reset(arg) {

  if(arg) return;

  set_light(1);

  short_desc="The beach beyond the dunes";
  long_desc="The beach backs into the sand dunes which lie to the west and " +
            "continues to the east until it meets the breaking waves of " +
            "the sea.  A horrible stench emanates from a pile of weeds " +
            "about halfway between the dunes and the sea.  Gulls are busy " +
            "squawking over the contents and tearing out bits of the " +
            "rotting entity.\n";

  dest_dir=({"/players/emerald/plain/b08","north",
             "/players/emerald/plain/b04","south",
             "/players/emerald/plain/b07","east",
             "/players/emerald/plain/d03","west",
             "/players/emerald/plain/b09","northeast",
             "/players/emerald/plain/d05","northwest",
             "/players/emerald/plain/b05","southeast",
             "/players/emerald/plain/d01","southwest",
           });

  items=({"beach","A white-sand beach",
          "dunes","Wind-blown accumulations of sand",
          "waves","Rolling foamy waves which break upon the sand",
          "sea","A clear blue sea",
          "pile","A pile of seaweed and other flotsom",
          "weeds","Seaweeds",
          "gulls","A bunch of noisy seagulls",
          "contents","Something dead and rotting",
          "bits","Small portions of the rotting thing",
          "entity","It was once alive",
        });

  smell="The foul reek of rotting flesh.\n";

  clone_list=({
    1,1,"gull","obj/monster", ({
      "set_name","seagull",
      "set_alias","gull",
      "set_race","bird",
      "set_short","An annoying seagull",
      "set_long","A hungry grey and white seagull.\n",
      "set_level",13,
      "add_money",135,
      "set_wc",9,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
