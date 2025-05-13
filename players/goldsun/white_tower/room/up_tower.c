inherit "/room/room";
#define TP this_player()


void reset(int arg){

    if (!arg){
	set_light(1);
	short_desc=("Tower temple");
	long_desc=
	"You have entered the top room of the tower. You can sense this is a most\n"+
	"holy place. There are golden candlesticks which light the room. The monks\n"+
	"come here to worship their god. There are stained glass windows which give\n"+
	"the room a multi-colored tint. The walls are decorated with elegant tapestries\n"+
	"which heighten the grandeur of the room. There is a circle on the floor which\n"+
	"has spiritual runes etched about it. The circle appears to have had something\n"+
	"in the center, but it is now empty. What could be inserted in ?\n";

	smell="You smell gods";
	dest_dir=({ "/players/goldsun/white_tower/room/inside","down"});
	property=({"no_teleport"});
	items=({ "tower",long_desc,
	  "floor","The only markings on the foor is a blue circle",
	  "circle","The circle appears to have surrounded a holy relic of the monks",
	  "runes","Holy runes surround the circle. They appear to be those used around altars",
	  "candlesticks","The golden candle sticks provide light. There are secured to the wall",
	  "candlestick","They provide light and are securely fastened to the wall",
	  "tapestries","The are made of rich velvet and depict religious heroes",
	  "windows","They depict stories of the holy wars",
	});
    }
    ::reset(arg);

}

init(){
    ::init();
    add_action("putd","insert");
    add_action("putd","place");
}


int putd(string str){
    object ob;

    notify_fail("Insert what where?\n");
    if (str=="altar in circle"){
	if (present("goldsun_quest_altar_for_white_tower",TP)){
	    ob=present("goldsun_quest_altar_for_white_tower",TP);

	    if (creator(ob) != "goldsun"){
		write("The Gods look angry.\n"+
		  "They growls: This is a fake !\n"+
		  "They writes a note in the sky.\n");
                log_file("QUESTS.CHEAT","white_tower"+this_player()->query_real_name()+
		  " object: "+file_name(ob)+" "+ctime(time())+"\n");
		destruct(ob);
		return 1;
	    }
	    write("You put altar in the circle.\n");
	    if (TP->query_quests() && 
	      ( member_array("white_tower",explode(TP->query_quests(),"#"))!=-1))
	    {
		write("The Gods grin at you.\nQuercus tells you: You have already solved"+
		  " this quest.\n");
		write_file("log/white_tower.2",TP->query_real_name()+
		  "  "+ctime(time())+"\n");
		return 1;
	    }

	    shout("The Gods happily thank "+TP->query_name()+".\n");
	    write("You solved this quest.\n");
	    TP->set_quest("white_tower");
	    //	write("A scroll appears.\n");
	    //        say("A scroll appears.\n");
	    //      move_object(clone_object("players/goldsun/white_tower/obj/scroll_quercus"),
	    //        this_object());
	    write_file("log/white_tower",TP->query_real_name()+
	      "  "+ctime(time())+"\n");
	    destruct(ob);
	    return 1;
	} 
	write("You haven't proper altar.\n");
	return 1;
    }
}

