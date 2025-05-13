

inherit "room/room";
object o1;

reset(arg) {
     if (!o1) {
       o1=clone_object("players/warlord/monsters/bas");
       move_object(o1,this_object());
      }
    if (arg) return;

    set_light(1);
    short_desc = "This is a nice decorated room";
    long_desc = 
           "This room also is decorated beautifully. You can hear sounds \n"+
           "of torture from all around you.\n";
    items =
          ({
           "walls","The walls are furnished with old armour and weapons",
          });
    dest_dir = 
        ({
        "players/warlord/rooms/fut1", "east",
        "players/warlord/rooms/fut4", "southeast",
        });
}


