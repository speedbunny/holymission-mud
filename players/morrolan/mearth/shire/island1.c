inherit "room/room";
object mon;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    property=({"no_teleport"});
    set_light(1);
    short_desc = "A small island";
    long_desc =
    "You are at a small island, this is a place where hobbits come to\n"+
    "think, relax, and get away form the hustle and bustle of life in\n"+
    "Shire.\n";
    if(!present("thinker")){
	mon=clone_object("/obj/monster");
	mon->set_name("Hobbit thinker");
	mon->set_alias("hobbit");
	mon->set_alt_name("thinker");
	mon->set_long("This is a hobbit that is deep in thought. He speculates about\n"+
	  "every single thing from why he was created to why is the world flat.\n"+
	  "His eyes drift dreamily about and there is minimal reaction to\n"+
	  "your presence here.\n");
	mon->set_race("hobbit");
	mon->set_size(2);
	mon->set_level(5);
	mon->load_chat(6,({
	    "Hobbit says: Why is the earth flat?\n",
	    "Hobbit says: Why were we created?\n",
	    "Hobbit says: To eat or not to eat... there's no question..\n",
	    "Hobbit says: What happens when we die?\n",
	    "Hobbit says: Why am I so short?\n",
	    "Hobbit says: Why am I wondering about these things?\n",
	  }));
	move_object(mon, this_object());
    }

}
