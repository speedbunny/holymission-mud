inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The back of the beach";
  long_desc="The beach slopes upwards gently to the west to meet the swell " +
            "of the dunes behind it.  It levels out to the east, where it " +
            "meets the breaking waves of the vast blue sea.  A few of the " +
            "dune weeds have spilled over to the edge of the beach, " +
            "clinging to a precarious existence which could be washed away " +
            "with a spring tide.\n";

  dest_dir=({"/players/emerald/plain/b10","north",
             "/players/emerald/plain/b06","south",
             "/players/emerald/plain/b09","east",
             "/players/emerald/plain/d05","west",
             "/players/emerald/plain/b11","northeast",
             "/players/emerald/plain/d07","northwest",
             "/players/emerald/plain/b07","southeast",
             "/players/emerald/plain/d03","southwest",
           });

  items=({"beach","A wide white-sand beach",
          "dunes","Mounds of accumulated sand",
          "waves","They wash up in constant rhythm against the beach",
          "sea","It extends as far as the eye can see to the east",
          "weeds","Salt-tolerant grasses and shrubs",
        });

  ::reset();
  replace_program("/room/room");

}
