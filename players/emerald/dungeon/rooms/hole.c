inherit "room/room";

void reset(int arg) {
        
    if(arg) return;

    set_light(1);

    short_desc="In a hole";

    long_desc="This is a dark, smelly hole.  There is an orange glow " +
              "emanating from the northwest exit.\n";

    dest_dir=({"players/emerald/dungeon/rooms/c18", "southeast",
               "players/emerald/dungeon/rooms/c22", "northwest",
               }); 

  items=({"glow","An evil orange glow of organic origin",
  });

  ::reset();
    replace_program("/room/room");
}

