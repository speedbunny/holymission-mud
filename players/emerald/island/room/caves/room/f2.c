inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";

  long_desc="The branches of the trees in this forest creak and groan as "+
            "the wind causes them to brush against each other.  Strange "+
            "shadows float over the ground, causing you to jump in fear.  "+
            "Off in the distance is the eternal rumbling of the volcano.\n";

  items=({"branches","They rub against each other, making frightful noises",
          "wind","An intermitten wind",
          "trees","Old and gnarled oaks and firs",
          "forest","A dark forest",
          "shadows","Horrifying patterns waft over the ground",
          "ground","It is covered in a thick layer of leaves and deadfall",
          "volcano","An unhappy and active volcano",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f3","east",
             "/players/emerald/island/room/caves/room/f1","west",
             "/players/emerald/island/room/caves/room/p6","south",
             "/players/emerald/island/room/caves/room/f6","north",
           });

  ::reset(arg);
  replace_program("/room/room");

}
