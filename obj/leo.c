#include "/sys/living.h"
#define SAY(x);		tell_room(environment(),x);


/*
 * This is the object wich tries to behave like Leo the archwizard.
 * The purpose is to converse with players and give them portable castles.
 */

string next_out;
object next_dest;
object give_him_castle;
int delay;

short() { return "Leo the Archwizard"; }

long() {
    write(short() + ".\n");
}

id(str) { return str == name; }

reset(arg) {
     ::reset(arg);
    if (arg)
	return;
    msgout = "leaves";
    msgin = "enters";
    name = "leo";
    cap_name = "Leo";
    next_out = 0;
    is_npc = 1;
    level = 40;
    alignment = 1000;
    weapon_class = WEAPON_CLASS_OF_HANDS;
    max_hp = 300;
    hit_point = 300;
    experience = 100;           /* Changed due to a bug.  Styles.  */
    enable_commands();
    spell_points = 300;
    stats=allocate(6);		/* now as an array. Herp */
}

run_away() { return 0; }

catch_tell(str)
{
    object from;
    string a;
    string b;
    string c;
    
    from = this_player();
    if (!from)
	return;	/* Not from a real player. */
    sscanf(str, "%s\n", str);	// Just to make sure.
    if (sscanf(str, "%sello%s", a, b) == 2 ||
	sscanf(str, "%s hi%s", a, b) == 2 ||
	sscanf(str, "%s Hi%s", a, b) == 2){
	next_out = "Welcome, " + call_other(from, "query_name", 0) + ".\n";
	if (from->query_level()==GM->query_levels(from->query_guild()))
	    next_out = next_out +
		"Now that you are a wizard, you can have a castle of your own.\n";
        delay=2;
	next_dest = from;
	set_heart_beat(1);
	return;
    }
    if (0 && sscanf(str, "%sgive%scastle%s", a, b, c) == 3 ||
	sscanf(str, "%swant%scastle%s", a, b, c) == 3) {
#if 0
SAY("short ["+from->short()+"]\n");
SAY("query_wizard ["+from->query_wizard()+"]\n");
SAY("query_guild ["+from->query_guild()+"]\n");
SAY("GM->query_levels(gd) ["+GM->query_levels(from->query_guild())+"]\n");
#endif
	if (from->query_level()==GM->query_levels(from->query_guild())) {
	    castle();
	    return;
	}
	next_out = "What ! Give a castle to you ?\n";
	next_dest = from;
	delay=2;
	set_heart_beat(1);
	return;
    }
    if (sscanf(str, "%s gives %s to Leo.", a, b) == 2) {
	object ob;
	ob = present(b, this_object());
	if (!ob || !call_other(ob, "id", "orc slayer"))
	    return;
	next_out = "Leo says: Well done. You have fullfilled this quest.\n";
	next_dest = from;
	set_heart_beat(1);
	call_other(from, "set_quest", "orc_slayer");
	destruct(ob);
	return;
    }
    if (sscanf(str, "%s arcanarton%s", a, b) == 2) {
        next_out = "Leo says: Search for the jem of arcanarton at the "+
                   "Isle of Magi.\n" +
                   "Leo says: The staff is somewhere near the village.\n";
        next_dest = from;
        delay = 2;
        set_heart_beat(1);
        return; 
    }
    log_file("LEO", "'"+str+"'\n");
}

/*
 * Always let the heart_beat do the talking, to simulate delay.
 */

heart_beat()
{
    age += 1;
    attack();
    if (random(80) == 1)
	say("Leo smiles.\n");
    if (delay>0) {
        delay -= 1;
        return;
    }
    if (next_out) {
	tell_object(next_dest, next_out);
	next_out = 0;
    }
    if (!attacker_ob)
	set_heart_beat(0);
}

castle() {
    write(
"You are now ready to take the step into true wizardhood. But, to do this,\n");
    write(
"you must select one wizard that will take responsibility for you.\n");
    write(
"He must also back up your claim of being a wizard, not by cheating.\n");
    write("If you have no name so far, come back here again.\n");
    write("Now give me the name: ");
    input_to("castle2");
}

castle2(back_up_wiz) {
    string castle_name;
    string player_name;
    string save_name;
    int save_level;
    object wiz;

    return;
  
    if (back_up_wiz == "") {
	write("Welcome back.\n");
	return;
    }
    back_up_wiz = lower_case(back_up_wiz);
    save_name = name;
    save_level = level;
    if (!restore_object("players/" + back_up_wiz)) {
	write("There is no player with that name.\n");
	return;
    }
    name = save_name;
    if (level < 50) {
	write("That player is not full wizard !\n");
	level = save_level;
	return;
    }
    if (!present(back_up_wiz,environment())) {
	write("That wizard is not here right now.\n");
	return;
    }
    wiz = find_living(back_up_wiz);
    if (wiz->query_linkdeath()) {
	write("That wizard is currently linkdead.\n");
	return;
    }
    if (!wiz->query_sponsor()) {
	write("This wizard is not allowed to sponsor new wizards.\n");
	return;
    }

    level = save_level;
    castle_name = clone_object("room/port_castle");
    player_name = call_other(this_player(), "query_name", 0);
    call_other(castle_name, "set_owner", player_name);
    move_object(castle_name, this_player());
    log_file("SPONSOR", back_up_wiz + " : " +
	call_other(this_player(), "query_name") + " " + ctime(time()) + "\n");
    tell_object(this_player(),
		"\n" +
		"Congratulations, you are now a complete god with your own\n" +
		"castle. But beware, you can only drop it once !\n" +
		"When it is dropped, it can never be moved again.\n" +
		"You will get more wizard command at next log in.\n");
    call_other(this_player(), "set_level", this_player()->query_level()+1);
    call_other(this_player(), "set_title", " the wizard");
}
