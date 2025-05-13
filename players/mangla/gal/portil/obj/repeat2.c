string name;
object player;

id(string str) { return (str=="repeater"); }

short() { return "A repeater"; }
long() { write("It works like converse but is usefull for repeating commands\nJust type repeat tell <name> or repeat shout to echo to all or\njust individuals.\n");
}

get() { return 1; }
drop() { return 0; }

init() {
        add_action("repeat","repeat");
        }

repeat(string str) {
        if(!str) {
                notify_fail("What command do you wan to use with repeat?\n");
                return 0;
        }
	if(str=="shout") {
	  write("** to stop!\n]");
	  input_to("more_shout");	
	  return 1;
	}
        if(sscanf(str,"tell %s",name)!=1) {
	  notify_fail("Repeater says: Not understood.\n");
	  return 0;
	}
	player = find_player(name);
	if(!player) {
	  write("That player isn't logged on.\n");
	  return 1;
	}
        write("** to stop!\n]");
        input_to("more_tell");
        return 1;
}

more_shout(string more) {
        if(more=="**") return 1;
	shout(more+"\n");
        input_to("more_shout");
        write("]");
        return 1;
}

more_tell(string more) {
        if(more=="**") return 1;
	if(player) tell_object(player,more+"\n");
        input_to("more_tell");
        write("]");
        return 1;
}
