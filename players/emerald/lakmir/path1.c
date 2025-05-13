inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A path through the forest";
  long_desc="You are travelling on a small path which winds through the " +
            "tall and dark trees of the forest.  Twigs and leaves litter " +
            "the path, muffling the sound of your footfalls on the ground.\n";

  dest_dir=({"/players/emerald/lakmir/forest0","north",
             "/players/emerald/lakmir/bifurcation","east",
             "/players/emerald/lakmir/meadow2","south",
             "/players/emerald/lakmir/fork","west",
           });

  items=({"path","A narrow winding path",
          "trees","Old oaks and beech",
          "forest","A conglomeration of dark trees",
          "twigs","Dead branches from the trees",
          "leaves","Oak and beech leaves",
          "ground","Loam",
        });  

  ::reset();
  replace_program("/room/room");
}
