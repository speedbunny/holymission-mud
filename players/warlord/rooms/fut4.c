

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/konji");
move_object(o1,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "Sacred chambers of Konji";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the Sacred Chambers of Konji, one of the high \n"+
        "and fairly powerful Sorcerors. I'd advise you to leave now!!!!\n";
    dest_dir = 
        ({
        "players/warlord/rooms/fut3", "northeast",
        "players/warlord/rooms/fut2", "northwest",
        "players/warlord/rooms/fut1", "north",
        "players/warlord/rooms/fut6", "southeast",
        "players/warlord/rooms/fut5", "southwest",
        });
}
init(){ ::init();
    add_action("southwest","southwest");
    add_action("southeast","southeast"); }
southwest(){
    if (present("konji")){ tell_room(this_object(),"Konji says: NO MORTAL MAY PASS !!!\n");
    return 1;
}
 return !this_player()->move_player("southwest#players/warlord/rooms/fut5");
}
southeast (){
  if (present("konji")) {tell_room(this_object(), "Konji says: NO MORTALS MAY PASS !!!\n");
  return 1;
}
 return !this_player()->move_player("southeast#players/warlord/rooms/fut6");
}


