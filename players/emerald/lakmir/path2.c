inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A path through the forest";
  long_desc="You are travelling on a path through the dark forest of the " +
            "Druid Lakmir.  Strange creakings and groaning can be heard " +
            "emanating from the foliage around you.  Chills run up and " +
            "down your spine as you hurry to find the end of the path.\n";

  dest_dir=({"/players/emerald/lakmir/forest3","north",
             "/players/emerald/lakmir/fork","east",
             "/players/emerald/lakmir/forest2","south",
             "/players/emerald/lakmir/clearing","west",
           });

  items=({"path","A narrow winding path",
          "forest","It reeks of evil",
          "foliage","Thick, dense leaves and branches",
       });

  ::reset();
  replace_program("/room/room");

}

