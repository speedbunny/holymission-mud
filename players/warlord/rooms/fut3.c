

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/redsor");
move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = " A very messy lab";
    long_desc = 
          " You have walked into a very big room there are a lot \n"+
          " of Books and scrolls lying around. You see a table filled \n"+
          " with flasks and beakers.\n";
    items =
          ({
           "book","The book is written in a language you cannot understand",
           "beakers","There are glass beakers here with liquids in them",
           "flasks","The flasks are empty and dirty",
           "scroll","The scroll is a language you cannot interpret",
           "table","the table is filled with smoke emulating glassware",
           "walls","The walls have a great deal of burn marks on them",
          });
    dest_dir = 
        ({
        "players/warlord/rooms/fut1", "west",
        "players/warlord/rooms/fut4", "southwest",
        });
}

