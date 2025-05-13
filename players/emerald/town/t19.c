inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A side street";

  long_desc="The silence of the area has been broken by the sound of metal " +
            "ringing on metal.  You guess that there must be a smithy in " +
            "the area.  You can also smell the scent of fresh hay and " +
            "straw.  A boy is leading a horse into the building to the " +
            "north of you.\n";
  dest_dir=({"/players/emerald/town/stable","north",
             "/players/emerald/town/smith","south",
             "/players/emerald/town/t18","east",
             "/players/emerald/town/t20","west",
           });

  items=({"building","A stable",
  });

  clone_list=({
    1,1,"boy","obj/monster", ({
      "set_name","boy",
      "set_race","human",
      "set_gender",1,
      "set_short","A stable boy",
      "set_level",10,
    }),
    2,1,"horse","obj/monster", ({
      "set_name","horse",
      "set_short","A horse",
      "set_level",28,
      "set_wc",15,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
