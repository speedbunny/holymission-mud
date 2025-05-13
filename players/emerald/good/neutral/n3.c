inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="Misty cloud world";
  long_desc="A chill breeze flows into a large chamber-like area in the "+
            "clouds.  The breeze flows in from small passages which lead "+
            "south and east.  The clouds around the passage leading "+
            "north have a touch of darker grey around their edges, looking "+
            "stormy and menacing.\n";

  dest_dir=({"/players/emerald/good/neutral/n5","north",
             "/players/emerald/good/neutral/n4","south",
             "/players/emerald/good/neutral/n22","east",
             "/players/emerald/good/neutral/n2","southwest",
           });

  items=({"breeze","A cold, damp breeze blowing from the east and south",
          "area","The clouds have parted, forming a large chamber",
          "passage","Small passages lead north, south, east, and southwest",
          "clouds","The clouds to the north appear to have a stormy core",
          "passage","The northern passage appears a bit stormy",
          "edges","The edges of the clouds are dark grey",
        });

  ::reset(arg);
  replace_program("/room/room");

}
