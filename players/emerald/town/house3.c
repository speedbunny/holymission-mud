inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="A house";

  long_desc="This is one of the average houses in town.  The furnishings " +
            "are on the nicer side.  Pegs are stuck in the wall near the " +
            "door for people's cloaks.  A table and some chairs are pushed " +
            "against the wall.\n";

  dest_dir=({"/players/emerald/town/t20","north",
           });
  items=({"table","A well-made oak table that has seen much use",
          "chairs","Oak chairs to match the table",
          "pegs","Stout wooden pegs for hanging clothing",
          "furnishing","The wooden occupants of the house",
        });

  ::reset(arg);
   replace_program("/room/room");

}
