inherit "obj/treasure";
string scent,note;

void long() {
    write(long_desc);
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
    set_value(10);
    scent="a lovely flower grown on the top of Ishikawa's largest mountain";
    note="from your secret admirer!";
}

void init() {
    add_action("flow_help","fhelp");
    add_action("send_flow","fsend");
    add_action("flow_desc","fdesc");
    add_action("flow_from","ffrom");
    add_action("smell_flow","smell");
    add_action("flow_scent","fsmell");
    add_action("read_note","read");
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

status send_flow(string str) {
    object who;

    if(!str) {
	write("Who do you want to send the starflower to?\n");
	return 1;
    }
    who=find_player(str);
    if(who) {
	tell_object(who,"Someone just sent you a Starflower!\n");
	transfer(this_object(),who);
	write("You send the starflower to "+who->query_name()+".\n");
    }
    else write("No such player.\n");
    return 1;
}

status smell_flow(string str) {
    if(str!="starflower" && str!="flower") return 0;
    say(this_player()->query_name()+" smells a starflower.\n");
    write("The starflower smells like "+scent+".\n");
    return 1;
}

status read_note(string str) {
    if(str!="starflower" && str!="flower") return 0;
    say(this_player()->query_name()+" reads a note tied to a starflower.\n");
    write("The note reads: "+note+"\n");
    return 1;
}

status flow_from(string str) {
    if(!str) str="From your secret admirer.";
    note=str;
    write("You change the note on the starflower.\n");
    say(this_player()->query_name()+" writes a note and ties it to a starflower.\n");
    return 1;
}

status flow_scent(string str) {
    if(!str) str="a lovely starflower, freshly picked just for you";
    scent=str;
    write("The starflower magically adjusts its scent!\n");
    return 1;
}

status flow_help() {
    write("Starflower help:\n"+
      "   fhelp   -   This message\n"+
      "   fdesc   -   Change the color of the starflower\n"+
      "   fsend   -   Send starflower to another player\n"+
      "   ffrom   -   Tie a note to the starflower\n"+
      "   fsmell  -   Change the scent of the starflower\n"+
      "   read    -   Read the note\n"+
      "   smell   -   Smell the starflower\n"+
      "\nAny comments can be mailed to Exos.\n");
    return 1;
}
