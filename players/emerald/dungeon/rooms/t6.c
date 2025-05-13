inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(0);

  short_desc="The castle sewers";

  long_desc="You are crawling around in a sewer passage under the castle.  " +
            "It's everything you imagined it would be: smelly, slimy, and " +
            "utterly revolting.\n";

  dest_dir=({"/players/emerald/dungeon/rooms/t5","north",
             "/players/emerald/dungeon/rooms/t7","southeast",
           });


  ::reset(arg);
   replace_program("/room/room");

}
