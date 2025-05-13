/*Room description corrected by Silas*/
inherit "room/room";

string race_name;

reset(arg) {
	if (arg) return;
    set_light(1);
    short_desc = "Conference and storage room";
    no_castle_flag = 1;
    long_desc = 
        "You entered a special room.\n";
    dest_dir = 
        ({
        });
}

init() {
	object iob;
	
	::init();
	iob = present("race-soul", this_player());
	if ((this_player()->query_level() < 50) && 
            (!iob || query_race() != call_other(iob, "query_race"))) {
		write("As you are not of the required race, the room kicks you away.\n");
		move_object(this_player(), "room/adv_guild");
		return 0;
		}
	add_action("get_armour", "dress");
	return 1;
}

init_room(race) {
	if (!race) return 0;
	race = capitalize(lower_case(race));
	short_desc = race + " conference and storage room";
	long_desc =
		"You entered a special room, especially designed for " + race + "s.\n" +
		"This room can only be entered by people of the " + race + " race.\n" +
		"You can use this room as a storage room for items which can be used\n" +
		"for all " + race + "s (so you can help all people of your own race).\n\n" +
		"HINT: Especially for newbies there is the function `dress`. Try it !!!\n\n";
	race_name = lower_case(race);
	return 1;
}

query_light() {
    return 1;
}

query_race() {
	return race_name;
}

get_armour() {
	object ob, jacket;
	string j_name;
	
	j_name = capitalize(race_name) + " jacket";
    ob = first_inventory(this_player());
    while (ob && !(ob->id(j_name)))
        ob = next_inventory(ob);
    if (ob) {
        tell_object(this_player(), "You cannot dress two race armours !!!\n");
        return 1;
        }
	jacket = clone_object("players/jug/obj/r_jacket");
	call_other(jacket, "set_name", j_name);
	call_other(jacket, "set_short", "A special " + capitalize(race_name) + " jacket");
	move_object(jacket, this_player());
	tell_object(this_player(), "You take a special jacket.\n");
	return 1;
}
