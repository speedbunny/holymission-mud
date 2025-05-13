inherit "obj/treasure";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("note");
    set_alias("notice");
    set_alt_name("poster");
    set_short("Note about a murder");
    set_long(
      "The note is a large piece of paper written in the careful\n"+
      "hand of a scribe and it is quite legible. The note invites\n"+
      "you to simply read it.\n");
    set_weight(10000);
    set_value(5000);
}

void init(){
    ::init();
    add_action("read", "read");
}

int read(string str){
    if(!str) return 0;
    if(id(str)){
	write("You read the note.\n");
	say(this_player()->query_name()+
	  " reads the note.\n", this_player());
	cat("/players/colossus/mearth/shire/murder_note",1,20);
	write("[Hit <CR> or return key to continue.]");
	input_to("next_page");
	return 1;
    }
}

void next_page(string str){
    cat("/players/colossus/mearth/shire/murder_note",21,12);
    return;
}
