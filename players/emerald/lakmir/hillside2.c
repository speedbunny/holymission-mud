inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="The bottom of a hill";
  long_desc="A large hill looms over the area, rising out of nowhere " +
            "to tower over the forest below.  The sides are not terribly " +
            "steep, allowing easy access to the top of the hill.  The " +
            "view from the top which overlooks the forest must be lovely.\n";

  dest_dir=({"/players/emerald/lakmir/hill2","up",
             "/players/emerald/lakmir/forest10","east",
          });

  items=({"hill","A big bump in the landscape",
          "forest","The dark forest of the Druid Lakmir",
          "sides","The sides of the hill are not steep",
          "view","It will probably be quite beautiful",
          "top","The top of the hill",
        });

  ::reset();
  replace_program("/room/room");

}

