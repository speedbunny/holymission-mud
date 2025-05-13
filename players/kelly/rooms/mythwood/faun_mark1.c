inherit "room/room";

object mon;

void reset(int arg) {

    ::reset();
    set_light(1);
    short_desc="The western part of the Fauns' market place";
    long_desc = "You are standing on the western part of the Faun Market Place.\n" +
                "The buying and selling in this part seems to be limited to the\n" +
                "residence of the village only. To the north you see an inn.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/faun_vill1","west",
               "players/kelly/rooms/mythwood/faun_mark2","east",
               "players/kelly/rooms/mythwood/fauninn","north",
             });
    items=({
            "inn","A rather large building, there is a sign with a unicorn above the door",
          });
    if(!objectp(mon)) {
    mon=clone_object("players/kelly/monster/faun");
    mon->set_name("faun");
    move_object(mon,this_object());
    }
}
