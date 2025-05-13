inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="King's Room";

  long_desc="The King of the Good World makes his home here.  He is a " +
            "jolly and rotund fellow with a gleam in his eyes.  You " +
            "notice the king is not at all surprised to see you here.  " +
            "He is sitting at his table, eating (as usual).  You feel " +
            "very relaxed in his presence.\n";

  dest_dir=({"/players/emerald/good/light/light24","north",
           });

  items=({"home","The home of King Ralph",
          "table","It is set with platters of delicious foods",
          "eyes","They sparkle with intelligence",
        });

  clone_list=({
    1,1,"king","/players/emerald/good/obj/king",0,
  });

  ::reset();
  replace_program("/room/room");

}
