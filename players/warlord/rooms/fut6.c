

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/lbas");
move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A long narrow hallway";
    long_desc = 
        "You're in a long hallway with strange noises coming from all around\n"+
        "There is a sign on the wall.\n";
     items =
          ({
          "sign","Don't go southeast or you'll regret it",
          });
    dest_dir = 
        ({
        "players/warlord/rooms/fut4", "northwest",
        "players/warlord/rooms/fut9", "southeast",
        "players/warlord/rooms/fut7", "southwest",
        "players/warlord/rooms/fut5", "west",
        });
}
init(){::init();
    add_action("southeast","southeast");
    add_action("southwest","southwest");}
southeast() {
    if(present("basilisk")){tell_room(this_object(),"Basilisk says: NO MORTALS MAY PASS !!!\n");
    return 1;
}
    return !this_player()->move_player("southeast#players/warlord/rooms/fut9");
}
southwest() {
    if(present("basilisk")){tell_room(this_object(),"Basilisk says: NO MORTAL SHALL PASS !!!\n");
    return 1;
}
    return !this_player()->move_player("southwest#players/warlord/rooms/fut7");
}


