

inherit "room/room";
    object mon0;

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "The forest on Arthur's island";
    no_castle_flag = 0;
    long_desc = 
   "	You are in a very thick forest, the light is somewhat dimmer here\n"
   + "which gives you the feeling that monsters would tend to hideout here more\n"
   + "often than in some of the other parts of the forest.\n"
   + "\n";
    dest_dir = ({
        "players/arthur/area/forest/forest21", "west",
        "players/arthur/area/forest/forest23", "east",
        "players/arthur/area/forest/forest16", "south",
        });
    items = ({
     });
   }
   if (!mon0 || !living(mon0)) {
    mon0=clone_object("players/arthur/area/monsters/formon");
    transfer(mon0,this_object());
   }
}

