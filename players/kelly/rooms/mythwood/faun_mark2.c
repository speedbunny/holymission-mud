inherit "room/room";


reset(arg) {

    set_light(1);
    short_desc="The eastern section of the market place";
    long_desc="You are standing in the eastern section of the Faun Market Place.\n" +
              "Steam and smoke are bellowing out the chimeny of the hut south of here.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/faun_mark1","west",
               "players/kelly/rooms/mythwood/faun_chief","east",
               "players/kelly/rooms/mythwood/faun_druid","south",
               "players/kelly/rooms/mythwood/faun_smith","northeast",
             });
    items=({
            "hut","Maybe this is the druid's hut and he's searching for new recipes",
            "steam","That is gaseous water if you did not already know",
            "smoke","Lots of really light particles floating in the air",
          });
}

