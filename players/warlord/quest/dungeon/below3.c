#define TP this_player()
#define TPN TP->query_name()
inherit"/players/warlord/NEWSTUFF/room";
object counter,ter;
int i,j;
reset(arg) {
    j=0;
    counter=0;
    if(!(ter=present("termite"))|| !living(ter))
	for(i=0;i<7;i++)
	    move_object(clone_object("players/warlord/quest/monsters/term"),this_object());
    if (arg) return;
    set_light(1);
    short_desc="termite room";
    long_desc="This room is lit by strange rocks on the wall. You see little\n"+
    "insects crawling all around.\n";
    items=({
      "rocks","The rocks are made of a strange material.\nMaybe you can chip a piece off?\n",
    });
    dest_dir=({
      "/players/warlord/quest/dungeon/below4","west",
      "/players/warlord/quest/dungeon/below5","east",
      "/players/warlord/quest/dungeon/below2","up",
    });
    return 1;
}
init() {
    add_action("chip","chip");
    ::init();
}
chip(str){
    object rock;
    if ( j<1){
	if(str=="rock"||str=="off rock"||str=="rocks"){
	    rock=clone_object("obj/torch");
	    rock->set_name("rock");
	    rock->set_short("Piece of rock");
	    rock->set_long("To light rock type: light rock.\n");
	    rock->set_full(4000);
	    rock->set_value(10);
	    rock->set_weight(2);
	    move_object(rock,this_object());
	    write("You have chipped a piece of the rock away.\n");
	    say(TPN+" has chipped a piece of the rock away.\n");
	    j=j+1;
	    return 1;
	}
	else{
	    write("That is not here.\n");
	}
	return 1;
    }
    else{
	write("You can't chip anymore off.\n");
    }
    return 1;
}
