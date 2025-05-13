int beat_count;
object client;

short() {
    return "The void";
}

long() {
    if (client)
	return 0;
    write(short() + ".\n");
    write("You come to the void if you fall out of a room, and have nowhere to go.\n");
    write("Give the command 'church', and you will come back to village church.\n");

    write("\nYou are transfered to the church...\n");
    church();
}

init() {
    add_action("church"); add_verb("church");
    add_action("getout"); add_verb("leave");
}

church() {
    if (client)
	return 0;
    client = this_player();
    beat_count = 0;
    set_heart_beat(1);
    return 1;
}

getout() {
    tell_object(this_player(),"You found a way out !\n");
    move_object(this_player(),"/players/padrone/lith/inside_nanny");
    tell_room(this_object(),this_player()->query_name()
                + " found a way out !\n");
    return 1;
        }

reset(arg)
{
    if (arg)
	return;
    set_light(1);
}

id(str) { return str == "void"; }

heart_beat() {
    if (client)
	client = present(client, this_object());
    if (beat_count == 0 && client) {
	tell_object(client, "*** ERROR: Generic rehash failed while swapping in objects.\n");
	tell_object(client, "Current object was obj/player95/, line 119\n");
	tell_object(client, "Anomaly in the fabric of world space.\n");
	beat_count = 1;
    }
    else if (beat_count == 1 && client) {
	beat_count = 2;
	tell_object(client, "Bus error (core dumped)\n  \n");
    }
    else if (beat_count == 2 && client) {
	beat_count = 3;
	tell_object(client, "It looks like a serious error has occured.\n");
	tell_object(client, "You feel weightless for a moment, and then you fall out of the game!\n");
	client->move_player("through an anomaly in the fabric of world space#players/padrone/lith/inside_nanny");
	/* Since move_player is done from the heart beat, client will not see the "look"! */
	tell_object(client, "You wonder were you are now...\n");
    }
    else {
	beat_count = 0;
	set_heart_beat(0);
	client = 0;
    }
} /* heart_beat */
