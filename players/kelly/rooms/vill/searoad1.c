inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A road";
    long_desc="You are on a road leading leading to the sea.\n"+
      "In the distant east you can see some sea-gulls flying high.\n"+
      "You can't go east, because there's a large gap in the middle of the street.\n";
    dest_dir=({
      "players/kelly/rooms/vill/road7","west",
    });
    items=({
      "sea-gulls","They are too far to see something special",
      "gap","It's seems to be unnatural",
    });
}
 
