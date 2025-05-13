inherit "room/room";
#define TP  this_player()


reset(tick){
    if(tick) return;
    set_light(1);
    short_desc=("A small throne room");
    long_desc=("This is a small throne room carved from the side of\n"+
      "the mountain. From here the Evil Timelord Thanos can watch\n"+
      "as the world below is destroied, then move in and take\n"+
      "over what is left.\n");
    move_object(clone_object("players/akira/mobs/thanos"), this_object());
    ::reset(tick);
    dest_dir=({"players/akira/vag/m3", "south" });
    property = ({ "no_teleprt", "vag_quest" });
}


void init() {
    add_action("smash_clock", "smash");
}


smash_clock(string arg) {
    object clock;
    clock = present("4thclock", this_object());
    if(!clock) {
	return 1;
    }
    if(!arg || arg != "clock" ) {
	write("Smash what?\n");
	return 1;
    }

    if(arg == "clock" ) {
	write("You throw the clock to the ground, smashing it.\n");
	destruct(clock);
	call_out("smash_sound", 3);
	return 1;
    }

    return 1;
}

smash_sound() {
    write("SMASH!!!!!!!\n");
    call_out("clock1", 3);
    return 1;
}

clock1() {
    write("You start to see rays shoot out from the tiny "+
      "pieces of the smashed clock.\n");
    call_out("clock2", 3);
    return 1;
}

clock2() {
    write("The rays continue to shoot around the room, and the"+
      "\n"+
      "room starts to flux all around you.\n");
    call_out("clock3", 3);
    return 1;
}


clock3() {
    write("The rays become to too immense and fill the room.\n");
    call_out("clock4", 3);
    return 1;
}



clock4() {
    write("Then there is a big flash of white light, that blinds you.\n");
    call_out("clock5", 3);
    return 1;
}


clock5() {
    write("You blackout....\n");
    call_out("goto_finish", 3);
    return 1;
}


goto_finish() {
    string path;
    path = "/players/nylakoorub/4th/quest/finish_room";
    move_object(TP, path);
    return 1;
}



