inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="A vast grassy plain";
  long_desc="The enchanted path lies to the west of this vast " +
            "grassy plain.  It is bordered to the north by the high, " +
            "sheer cliffsides of immense grey mountains.  Nothing but the " +
            "rippling waves of grass can be seen further to the south " +
            "and east.  The bright blue sky overhead is unbroken by " +
            "clouds.  Off in the distance, you hear the distinctive cry " +
            "of an eagle.\n";

  dest_dir=({"/players/emerald/plain/p32","east",
             "/players/kryll/rooms/path/ep17","west",
             "/players/emerald/plain/p23","south",
             "/players/emerald/plain/p24","southeast",
             "/players/kryll/rooms/path/ep16","southwest",
           });

  items=({"plain","A broad section of flat grassland",
          "cliffsides","They cannot be climbed",
          "mountains","Their peaks are capped with snow",
          "waves","The wind bends the grass in waves",
          "grass","It ripens to gold in the sunlight",
          "sky","It is an intense azure",
          "path","The enchanted path",
          "clouds","The sky is free of clouds",
        });

  ::reset();
  replace_program("/room/room");

}
