

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/guard2");move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "hill";
    no_castle_flag = 0;
    long_desc = 
        "This is the top of a beautiful hill. The castle up here is small\n"
        + "but magnificent. There are beautiful columns and arches here.\n";
    items = ({
          "columns","The columns are made from real marble",
          "castle","It looks small but elegant with its arches and columns",
           "arches","The arches have beautiful drawings carved into them",
});
    dest_dir = 
        ({
        "players/warlord/hill2", "down",
        "players/warlord/rooms/entrance", "enter",
        });
}


