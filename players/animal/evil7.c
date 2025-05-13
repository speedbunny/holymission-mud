inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Underground river";
    no_castle_flag = 0;
    long_desc = "Underground river\n\n"+
     "    A small underground river is flowing from underneath a\n"+
     "    cavern wall here. The river is dark and forboding. It looks\n"+
     "    like more than one person has drowned here, as there are\n"+
     "    bones lying around on the banks.\n\n";
    dest_dir =
        ({
        "/players/animal/evil6", "west",
        });
     items = ({
     "river","The river is dark and it does not look too friendly",
     "bones","The bones of many adventurers lay on the banks here",
	});
}
 
query_long() {
    return long_desc;
}
 
query_light() {
    return 1;
}
