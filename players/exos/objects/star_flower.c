inherit "obj/treasure";
string scent,note;

string query_auto_load() {
    return ( "/players/exos/objects/star_flower:" );
}

void long() {
    write(long_desc);
}

int drop() {
    write( "You don't want to drop your flower!\n" );
    return( 1 );
}

void reset(int arg) {
    if(arg) return;
    set_id("flower");
    set_name("starflower");
    set_alias("star");
    set_short("A magical starflower");
    set_long("\
This is a beautiful blue starflower!\n\
And it is magical!  Just type <fhelp>.\n");
    set_weight(0);
    set_value(0);
}

void init() {
    add_action("flow_help","fhelp");
    add_action("flow_desc","fdesc");
}

status flow_desc(string str) {
    if(!str) {
	write("Use 'fdesc <description>' to change the starflower.\n");
	return 1;
    }
    this_object()->set_short("A single "+str+" starflower");
    this_object()->set_long("It is a beautiful "+str+" starflower!\n"+
      "And it is magical!  Just type 'fhelp'.\n");
    write("The starflower magically changes into "+str+"!\n");
    return 1;
}

status flow_help() {
    write("Starflower help:\n"+
      "   fhelp   -   This message\n"+
      "   fdesc   -   Change the color of the starflower\n"+
      "\nAny comments can be mailed to Exos.\n");
    return 1;
}
