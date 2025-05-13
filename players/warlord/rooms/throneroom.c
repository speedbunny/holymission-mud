

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This is Warlord's Throne room. All the furniture is made of Oak and Brass.\n"
        + "Even the throne is a work of art itself. There are pictures and paintings\n"
        + "on the wall showing all of his Greatest triumphs.\n";
   items=({
"pictures","The pictures are all of Warlord vaquishing beasts",
"furniture","There is a throne in the room",
"paintings","The paintings are all done in oil",
"throne","The throne is elegant looking",
         });
    dest_dir = 
        ({
        "players/warlord/rooms/hallway3", "north",
        });
}

