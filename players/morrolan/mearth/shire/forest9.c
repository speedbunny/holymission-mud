inherit "/room/room";
int sleeper;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    property=({"no_teleport", "no_fight"});
    set_light(0);
    short_desc = "In the Hobbit forest";
    long_desc =
    "There is a very neutral feeling here. A certain amount of peace\n"+
    "fills this tiny corner of the forest. It feels so peaceful that\n"+
    "you have to fight off the feeling of sleepiness that threatens to\n"+
    "overtake you.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest6", "north",
      "/players/colossus/mearth/shire/forest7", "west",
    });

}

void init(){
    ::init();
    add_action("look", "look");
    add_action("wakeup", "wakeup");
    add_action("wakeup", "wake");
    add_action("nomove", "north");
    add_action("nomove", "south");
    add_action("nomove", "east");
    add_action("nomove", "west");
    call_out("sleep", 1, this_player());
}

void sleep(){
    sleeper=1;
    write("You drift off to deep slumber.\n");
    say(this_player()->query_name()+" succumbs to sleep and starts dreaming.\n");
    this_player()->set_position(3);
    call_out("dream", 15, this_player());
}

void dream(){
    write("You dream about knights in shining armour, the terror of the ring\n"+
      "wraiths and the search for a hero. You see men on horses charging down\n"+
      "from mountains and elves firing their graceful longbows.\n"+
      "Then suddenly you see this Red Eye looking at you. You cower in fear\n"+
      "and try to avoid its gaze to no avail. You start to scream for help\n"+
      "when suddenly...\n\n");
    call_out("wake", 18, this_player());
}

void wake(){
    write("You wake up screaming in fear! You look around and you're back\n"+
      "at where you first started.\n");
    say(this_player()->query_name()+" wakes up screaming in fear!\n");
    this_player()->set_position(0);
    sleeper=0;
}

int look(){
    if(!sleeper) return 0;
    if(sleeper){
	write("You're asleep, you do not see anything!\n");
	return 1;
    }
}

int wakeup(){
    if(!sleeper) return 0;
    if(sleeper){
	write("Despite your best efforts you cannot wake up!\n");
	return 1;
    }
}

int nomove(){
    if(!sleeper) return 0;
    write("You cannot do that while sleeping!\n");
    return 1;
}
