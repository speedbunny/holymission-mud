

inherit "room/room";
    object mon0;
    object mon1;
    object mon2;

reset(arg) {

    if (!arg) {

    set_light(1);
    short_desc = "The forest on Arthur's island";
    no_castle_flag = 0;
    long_desc = 
   "	You are in a very thick forest, the light is somewhat dimmer here\n"
   + "which gives you the feeling that monsters would tend to hideout here more\n"
   + "often than some of the other rooms in the forest.\n"
   + "\n";
    dest_dir = ({
        "players/arthur/area/forest/forest14", "north",
        });
    items = ({
     });
   }
   if (!mon0 || !living(mon0)) {
    mon0=clone_object("players/arthur/area/monsters/formon");
    transfer(mon0,this_object());
   }
   if (!mon1 || !living(mon1)) {
    mon1=clone_object("players/arthur/area/monsters/formon");
    transfer(mon1,this_object());
   }
   if (!mon2 || !living(mon2)) {
    mon2=clone_object("players/arthur/area/monsters/formon");
    transfer(mon2,this_object());
   }
}

