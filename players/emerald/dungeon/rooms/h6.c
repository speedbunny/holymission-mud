inherit "room/room";

void reset(int arg) {

  if(arg) return;
    set_light(0);
    short_desc="A watery hall in the dungeon";
    long_desc="You are slogging through a water up to your calves.  " +
              "Slime floating on top of the water clings to your legs.  " +
              "The floor underneath the water is uneven, causing you to " +
              "stumble and slide.  However, the thought of steadying " +
              "yourself along the wall is just as repulsive as the prospect " +
              "of falling in the water.\n";

    dest_dir=({"players/emerald/dungeon/rooms/h5", "north",
               "players/emerald/dungeon/rooms/h7", "east",
             });


    items=({"walls", "The word 'slimy' comes to mind",
            "slime","Nice green slime.  Ick",
            "water", "Murky water with a film of slime",
            "floor","It is hidden under the water",
          });
  ::reset();
  replace_program("room/room");

}
