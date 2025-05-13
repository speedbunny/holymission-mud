inherit "room/room";

void reset(int arg) {

    set_light(1);

    short_desc="Road";

    long_desc=
              "You are on a road going out of the village. " +
              "The distant ruin of the ocean is heard to the east " +
              "while the town lies west.\n";

    dest_dir=({
               "room/vill_road3","west",
               "room/vill_shore2","east"
             });

    clone_list = ({ 1, 1, "beatrice", "/players/moonchild/misc/beatrice", 0,
                 });

    ::reset(arg);
    replace_program("room/room");
}

