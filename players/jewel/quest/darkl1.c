inherit "room/room";

reset(arg) {
    if (!arg) {
        set_light(1);
        short_desc="The dark land entrance";
        long_desc=
          "You are standing at the entrance to the dark lands. To the north\n"+
          "in a very far distance you can see a large black building.\n"+
          "To your south you notice a strange magical field.\n";
        items=({ 
          "building","This building looks like a large black castle",
          "field","It's pure darkness. It seems to suck in all light",
              });
        dest_dir=({
            "/players/jewel/quest/darkl2","north",
            "/players/jewel/quest/church2","south"
             });
    }
}
