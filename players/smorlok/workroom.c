#define NAME "smorlok"
inherit "room/room";
#define CNAME   capitalize(NAME)
object board;
void reset(int arg) {
/*
if(!board)
    {
        board = clone_object("/obj/board");
        board->set_name("Smorlok's arrival board.");
        board->set_file("/players/smorlok/board/work");
        board->set_short("Smorlok's Arrival Board.");
        transfer(board,this_object());
    }
*/
   ::reset(arg);
transfer( clone_object("/players/smorlok/board/work"), this_object() );

    set_light(1);
    short_desc=CNAME + "'s workroom",
    long_desc=
              "This is the workroom of "+CNAME+".\n" +
              "It looks empty ...\n";
    dest_dir=({
               "room/post", "post",
               "/players/smorlok/boardroom", "boardroom",
               "room/church", "church",
               "room/adv_guild", "guild", 
             });
    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
               });
    replace_program("room/room");
}
/*
init() {
    ::init();
    add_action("_blah","blah");
}
*/
