inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="the boardconnector";

    long_desc="A large room with many portals leading to many" +
              "spots on holy mission.\n";

    dest_dir=({ "/players/matt/newworld/entry", "nworld",
                "/players/wilbie/graveyard/trail1", "graveyard",
                "/players/saffrin/area/pk/room/d", "asylum",
                "/players/nylakoorub/clearing/path/rooms/c017", "clearing",
                "/players/turbo/rooms/r1", "turbo",
                "/players/beardy/valhalla/room/floor001", "valhalla",
                   });

    ::reset(arg);
    replace_program("room/room");
}
