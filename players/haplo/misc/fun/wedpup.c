inherit "obj/monster";
#define ENV environment
object who;
string chats;

reset(arg) {
    ::reset(arg);
    if (!arg) {
	set_name("puppy");
	set_level(10);
	set_hp(100);
	set_race("dog");
	set_short("Lab puppy");
	set_long("A lab puppy with a big red bow and a tag on it.\n");
	set_wc(10);
	set_ac(10);
	set_aggressive(0);
	if (!chats) {
	    chats=allocate(3);
	    chats[0]="Puppy barks happily.\n";
	    chats[1]="Puppy wags his tail.\n";
	    chats[2]="Puppy jumps up and licks your face.\n";
	}
	load_chat(5,chats);
    }
}

init() {
    ::init();
    add_action("read","read");
}

read(str) {
    if (str = "dog tag") {
     write("The tag reads: Belongs to Wednesday.\n");
	return 1;
    }
}

heart_beat() {
    who = find_player("wednesday");
    ::heart_beat();
    if (who && ENV(who)) {
	if (ENV(who) != ENV(this_object())) {
	    move_object(this_object(),ENV(who));
     tell_room(ENV(this_object()), "Puppy arrives following Wednesday .\n");
	}
    }
}
