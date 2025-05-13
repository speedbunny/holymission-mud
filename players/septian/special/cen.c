inherit "room/room";
void reset(int arg)  {
    ::reset(arg);
    set_light(1);
    short_desc="A room with many exits";
    long_desc="This is the central wizard room, it has many exits\n";
    dest_dir=({"/room/church","church",
      "/players/matt/newworld/city/rooms/votebooth","vote",
      "/room/post","post",
      "/players/blade/guild/hideout","hideout",
      "/players/blade/guild/room","thief"});
    replace_program  ("room/room");
}
