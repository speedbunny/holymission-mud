inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A hillside";
  long_desc="You have left the dark forest and started climbing a steep " +
            "hill.  It is quite rocky, and the vegetation is rather " +
            "sparse.  What plants are growing here look at bit charred, as " +
            "if something has burned them recently.\n";

  dest_dir=({"/players/emerald/lakmir/forest8","east",
             "/players/emerald/lakmir/hill1","up"
          });

  items=({"forest","A dark and forbidding forest",
          "hill","It is rather difficult to climb",
          "vegetation","There isn't much of it",
          "plants","They look a bit charred",
        });

  ::reset();
  replace_program("/room/room");

}

