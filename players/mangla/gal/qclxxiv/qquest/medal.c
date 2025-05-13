inherit "/players/qclxxiv/qtool";
#define PNAME this_player()->query_name()
#define COST 30   /* shout and tell has to cost something */
#define FILENAME "players/qclxxiv/qquest/medal"
 
#define SHOUT(x) gTellstring=x; filter_array(users(),"filter_tell",this_object())

static string gTellstring;
string say_string, tell_string, shout_string;
int echo;
 
filter_tell(ob) {
    if (ob == this_player()) return 0;
    return ob->catch_shout(gTellstring);
}

id(str) { return str == "medal" || str == "qquest_medal"; }
long() {
	write(
"A golden 7-fingered leaf shaped medal. The highest decorations given out\n"
+"by the Q's of the 7-fingered Leaf. It is beautiful and shimmers magically.\n"
+"           |            \n"
+"        \\  |  /         \n"
+"         \\ | /          \n"
+"          \\|/           \n"
+"       ----V----        \n"
+"          /|\\           \n"
+" Njaq Njoq | Inu Draka  \n"
+"\n(type qspecial for additional information)\n"
		);
}
get() { return 1; }
drop() { return 1; }
query_quest_item() { return 1; }
query_weight() { return 0; }
query_value() { return 1000; } /* But shops CAN't take it from players */
query_auto_load() { return FILENAME+":"+echo; }

reset(arg) {
	if (arg) return;
	set_name("medal");
	set_short( "A golden 7-fingered leaf shaped medal");
	set_qsay("eloquently speaketh");
	set_qtell("eloquently informs");
	set_qshout("the Island Dragon Slayer,");	
}

dest(arg) {
	if (arg=="medal")  {
		destruct(this_object());
		return 1;
	}
	return 0;
}

qspecial()  { 
	write("The medal has a built-in Qmunicator only for Dragon Slayers.\n"
	+"They DECLAIM , INFORM, and SPEAK rather than shout, tell, or say!\n"
	+"This Special Qmunicator allows you to dsay, dtell, dshout, Dsay,\n"
	+"Dtell, and Dshout things in the style of normal say, tell, and shout.\n"
	+"But using: set_dsay, set_dtell, and set_dshout, you can define your\n"
	+"own verbs: like after 'set_dsay whispers', 'dsay something' will result\n"
	+"in other people hearing: your_name whispers something.\n"
	+"dtell and dshout DO add ' thee' or 'declaims' though.\n"
	+"The D versions do the same as d versions, only all text is uppercase:\n"
	+"i.e. Dtell hop bastard! makes hop hear: your_name informs thee: BASTARD!\n"
	+"Currently the settings are\n"
	+"(dsay)  : "+say_string+"\n"
	+"(dtell) : "+tell_string+"\n"
	+"(dshout): "+shout_string+"\n"
	+"To get rid of the gadget: destroy medal\n"
	+"In honor of the first player to slaughter the Island Dragon, a command\n"
	+"to set echo of the qmunicator on and off has been added: decho <on|off>.\n"
	+"\n"); 
    return 1;
}

set_echo(str) {
	if (str=="on") echo=1;
	if (str=="off") echo=0;
	write( (echo) ? "echo on.\n" : "echo off.\n" );
	return 1;
}

init()  { 
	::init();
	add_action("qspecial","qspecial");
	add_action("qsay", "dsay" );
	add_action("set_echo", "decho" );
	add_action("qtell", "dtell" );
	add_action("qshout", "dshout" );
	add_action("QQsay", "Dsay" );
	add_action("QQtell", "Dtell" );
	add_action("QQshout", "Dshout" );
	add_action("set_qsay", "set_dsay" );
	add_action("set_qtell", "set_dtell" );
        add_action("set_qshout", "set_dshout" );
	add_action("dest", "destroy");
}

set_qsay(str) {
	say_string = str;	
	return 1;
}
set_qtell(str) {
	tell_string = str;	
	return 1;
}
set_qshout(str) {
	shout_string = str;	
	return 1;
}

uppercase(arg) {
	return call_other("/players/qclxxiv/string","upper_case",arg);
}

qsay(str) {
	say( PNAME+" "+say_string+": "+str+"\n", this_player() );
	if (echo)
		write("You "+say_string+": "+str+"\n");
	else write("Ok.\n");
	return 1;
}
QQsay(str) { return qsay(uppercase(str)); }

qtell(str) {
	string target, mssg;

	if (this_player()->query_spell_points()<(COST/6)) {
		write("You are too low on power.\n");
		return 1;
	}
	if (sscanf(str, "%s %s", target, mssg)==2) {
		if (find_player(target)) {	
			tell_object( find_player(target),
					PNAME+" "+tell_string+" thee: "+mssg+"\n");
                        this_player()->restore_spell_points(-(COST/6));
			if (echo)
				write("You "+tell_string+" "+target+": "+mssg+"\n");
			else write("Ok.\n");
		}
		else write("Can't find any mortal with that name.\n");
		return 1;
	}
	write( "Tell whom what?\n");
	return 0;
}

QQtell(str) {
	string target, mssg;

	if (this_player()->query_spell_points()<(COST/6)) {
		write("You are too low on power.\n");
		return 1;
	}
	if (sscanf(str, "%s %s", target, mssg)==2) {
		if (find_player(target)) {	
			mssg = uppercase(mssg);
			tell_object( find_player(target),
						PNAME+" "+tell_string+" thee: "+mssg+"\n");
                        	this_player()->restore_spell_points(-(COST/6));
			if (echo)
				write("You "+tell_string+" "+target+": "+mssg+"\n");
			else write("Ok.\n");
		}
		else write("Can't find any mortal with that name.\n");
		return 1;
	}
	write( "Tell whom what?\n");
	return 0;
}

qshout(str) {
	SHOUT( PNAME+" "+shout_string+" declaims: "+str+"\n" );
	write( PNAME+" "+shout_string+" declaims: "+str+"\n" );
	this_player()->restore_spell_points(-(COST));
	return 1;
}
QQshout(str) { return qshout(uppercase(str)); }

init_arg(arg) {
    if (!arg) return;
	echo = arg;
}

