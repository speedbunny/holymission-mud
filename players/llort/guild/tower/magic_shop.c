inherit "room/room";

reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_light(1);
        property = ({"no_sneak"});
        short_desc="Magic shop";
        long_desc=
"You are in a little dim room. There are shelves all over the walls. You notice\n"+
"a sign located behind the counter. An old man with a long white beard, \n"+
"clothed in a long black robe with lots of runes and a large hat is standing\n"+
"behind the counter. He looks confused in your direction.\n";
        items=({ "wall","There are lots of shelves fixed to the walls",
                 "walls","There are lots of shelves fixed to the walls",
                 "shelf","Lots of strange things fill the shelves",
                 "shelves","Lots of strange things fill the shelves",
                 "sign","The sign reads:\n...Please no fights here!..",
                 "counter","An old oaken table, now used as counter",
              });
        dest_dir=({ "players/llort/guild/tower/hall2","east",
                    "players/llort/guild/tower/store_room","north" });
    }
    if(!present("wuntvor",this_object()) &&
       (!find_object("players/llort/guild/tower/store_room") ||
       !present("wuntvor",find_object("players/llort/guild/tower/store_room"))))
        move_object(clone_object("players/llort/guild/monster/wuntvor"),
                    this_object());
}

init() {
    ::init();
    this_player()->stop_fight();
    this_player()->stop_fight();
    this_player()->stop_hunter(1);
    call_out("hello",0,this_player());
}

hello(tp) {
    object wu;
    if((wu=present("wuntvor",this_object())) && tp->short() && tp!=wu) {
        say("Wuntvor says: Hello "+capitalize(tp->query_name())+
              " how can I help you?\n");
        write("Wuntvor says: Hello "+capitalize(tp->query_name())+
              " how can I help you?\n");
    }
}

try_attack(ob) {
    if(present("wuntvor",this_object()))
        tell_object(ob,"Wuntvor looks angryly at you.\n");
}

no() { return 1; }
