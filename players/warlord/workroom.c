inherit "room/room";
object o1;
object board;

reset(arg) {
    if (!o1) {o1=clone_object("players/warlord/rose");move_object(o1,this_object());}
    if (!board) {
	board = clone_object("obj/board");
	board->set_file("/players/warlord/mentee");
	board->set_short("Board for ninja discussions");
	board->set_name("mentee");
	move_object(board,this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc = "Warlord's Workroom\n";
    long_desc = 
    "This is the workroom of Warlord.\n";


    dest_dir = 
    ({
      "/players/kitty/workroom","kitty",
      "/players/warlord/guild/clerichome","guild",
      "/room/post","post",
      "/room/adv_guild","adv",
      "/players/moonchild/workroom","mw",
      "/obj/tick","tick",
      "/room/church","chur",
    });
}


init() {
    ::init();
    add_action("blah","blah");
}
blah(){
    int TestVar;
    TestVar= 1;
save_object("/players/warlord/fred");
    return;
}
