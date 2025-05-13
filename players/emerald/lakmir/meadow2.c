inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A blooming meadow";
  long_desc="You are in the middle of a large meadow.  Flowers intermingle " +
            "with the bright green blades of grass.  Butterflies dart " +
            "here and there, first going to one flower, then the next.  " +
            "Honey bees are also busy gathering nectar from the blossoms.\n";

  dest_dir=({"/players/emerald/lakmir/path1","north",
             "/players/emerald/lakmir/road","east",
             "/players/emerald/lakmir/meadow1","south",
             "/players/emerald/lakmir/path3","west",
           });
  items=({"meadow","An area of grass and flowers",
          "flowers","Bright blossoms in different colours",
          "blades","The leaves of grass",
          "grass","It is green and soft underfoot",
          "butterflies","Small butterflies happily lighting from flower " +
                        "to flower",
          "bees","They take no notice of your presence",
          "nectar","It attracts the bees and butterflies to the flowers",
          "blossoms","Flowers",
       });
   
  ::reset();
  replace_program("/room/room");

}
