inherit "room/room";

object brownie;

reset(arg) {

    if (arg) return;
    set_light(1);
    short_desc="A clearing in Mythwood";
    long_desc="You are standing in a clearing in Mythwood.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/clear6","north",
               "players/kelly/rooms/mythwood/clear1","west",
               "players/kelly/rooms/mythwood/clear4","northwest",
             });
    clone_list = ({ 1, 1, "brownie", "players/kelly/monster/brownie", 0,
                 });
    ::reset();
    replace_program("room/room");
}

