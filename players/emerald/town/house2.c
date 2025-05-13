inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A house";

  long_desc="You have entered a house full of lively, bouncy children.  " +
            "Their harried mother is busy trying to sew some patches in " +
            "their clothing, but she's not getting very far.  The smallest " +
            "of them are taking great delight in pushing the chairs and " +
            "table around the room and hearing the squeaking noises they " +
            "make.  The larger ones have taken up chasing the dog.\n";

  dest_dir=({"/players/emerald/town/t10","north",
           });
  items=({"table","A well-made oak table that has seen much use",
          "chairs","Oak chairs to match the table",
          "pegs","stout wooden pegs to hold clothing",
        });

  clone_list=({
    1,1,"mother","obj/monster", ({
      "set_name","mother",
      "set_race","human",
      "set_gender",2,
      "set_short","A busy mother",
      "set_level",15,
    }),
    2,4,"child","obj/monster", ({
      "set_name","child",
      "set_race","human",
      "set_short","A rambunctious child",
      "set_level",5,
    }),
    3,1,"dog","obj/monster", ({
      "set_name","dog",
      "set_short","A friendly dog",
      "set_level",3,
      "set_race","dog",
    }),
  });

  ::reset(arg);
   replace_program("/room/room");

}
