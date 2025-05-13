
#define ERROR_LOG "/log/BOARD"
#define MAX_MSG 120
#define GM "guild/master"
#define USERS ({"sauron","misticalla"}) // Sauron - edited for new Monk admin
#include "/sys/levels.h"

string new_head, new_text, tmp_head, tmp_text;
int msg_num;

static string file,name;
static string  messages, headers;
static int line, looked_at;
static object curr_writer;
static string short_name;
static string property;		/* routines to modify needed ? */

id(str) { 
  if (!str) return;
  return str == "board" || str == name+" board" || str == name+"board";
}

/* USERDOC:
set_file
Format: set_file(s)
Example: set_file("players/cashimor/save/board")
This function sets the file the board is saved in. Make sure the path to this
file is correct.
*/
set_file(str) { 
  file=str; 
}

set_name(str) { name=str; short_name="a "+name+" board"; }

set_short(str) { short_name=str; }

mixed query_property(string str) {
    int i;
    if (str == 0)
 return property;
    if (!property)
 return 0;
    if (stringp(property))
 return str == property;
    return member_array(str, property) != -1;
}

long() {
	string l;
	int ind;
	l="This is "+short_name+".\n" +
         "If you are monk or a special friend of monks, you can write\n"+
         "something on the board here. Use the command 'note header',\n"+
         "if you want to post a new and 'read number' if you want to\n"+
         "read a note.\n"; 

   if (member_array(this_player()->query_real_name(),USERS)!=-1)
      l = l + "As special friend, you are too allowed to delete old notes.\n";

	if (!msg_num) {
		l+="The board is empty.\n";
		return;
	}
	else {
		l+="The "+name+" board contains " + msg_num;
		if (msg_num == 1)
			l+=" note :\n\n";
		else 
			l+=" notes :\n\n";
	/*
		say(this_player()->query_name() + " studies the "+name+" board.\n");
	*/
		ind = 0;
		while (ind < msg_num) {
			l+=ind + 1 + ":\t" + headers[ind] + "\n";
			ind++;
		}
	}
	this_player()->more_string(l);
}

short() {
  if(msg_num==1) return capitalize(short_name) + " [ 1 note ]";
  return capitalize(short_name) + " [ " + msg_num + " notes ]";
}

get() {
	write("It is firmly secured to the ground.\n");
	return 0;
}

init() {
    if (interactive(this_player()))
  {
	add_action("new_msg", "note");
	add_action("read_msg", "read");
	add_action("remove_msg", "remove");
   }
	property="no_hide";
	if (!looked_at) {
	        int i;
		string arr;
		messages = allocate(MAX_MSG);
		headers = allocate(MAX_MSG);
		looked_at = 1;
		if (!restore_object(file))
		    return;
		arr = explode(tmp_head, "\n**\n");
		i = 0;
		while(i < sizeof(arr)) {
		    headers[i] = arr[i];
		    i++;
		}
		arr = explode(tmp_text, "\n**\n");
		i = 0;
		while(i < sizeof(arr)) {
		    messages[i] = arr[i];
		    i++;
		}
		tmp_text = "";
		tmp_head = "";
	}
}

reset(arg) {
	if (arg)
		if (!random(5)) {
			say("A small gnome appears and secures some " +
			"notes on the board that were loose.\n");
			say("The gnome leaves again.\n");
		}
}

new_msg(msg_head) 
{
	line = 1;
	if (!msg_head)
		return 0;
	if (this_player()->query_guild()!=7 && 
            this_player()->query_level() < 30 &&
       member_array(this_player()->query_real_name(),USERS)==-1) 
   {
		write("Only Monks can leave here their notes !\n");
		return 1;
	}
	if (curr_writer && this_player()!=curr_writer &&
		environment(curr_writer) == environment(this_object())) {
		write(curr_writer->query_name() + " is busy writing.\n");
		return 1;
	}
	if (msg_num == MAX_MSG) {
		write("You have to remove an old message first.\n");
		return 1;
	}
	if (strlen(msg_head) > 50) {
		write("Message header too long. Try again.\n");
		return 1;
	}
	curr_writer = this_player();
	say(curr_writer->query_name() + " starts writing a note.\n");
	new_head = msg_head;
	new_text = "";
	input_to("get_msg");
	write("Enter message text. End with '**', abort with '~q'.\n");
	write("1>>");
	return 1;
}

get_msg(str) {
	string filename;
	if (str == "~q") {
		say(curr_writer->query_name() + " aborts writing a note.\n");
		write("Note aborted.\n");
		curr_writer = 0;
		new_head = "";
		new_text = "";
		return;
	}
	if (str == "**") {
		if (line == 1) {
			write("No text entered. Message discarded.\n");
			say(curr_writer->query_name() + " quits writing.\n");
			curr_writer = 0;
			new_head = "";
			new_text = "";
			return;
		}
		say(curr_writer->query_name() + " has completed a note : " +
			new_head + "\n");
		headers[msg_num] = new_head + "(" +
		  capitalize(this_player()->query_real_name()) +
			", " + extract(ctime(time()), 4, 9) +
			", " + this_player()->query_level() + ")";
		messages[msg_num] = new_text + "\n";
		msg_num++;
		save_board();
		write("Ok.\n");
		curr_writer = 0;
		return;
	}
	if(this_player()->query_newwiz() && sscanf(str, "~r %s", filename)) {
		string text;
		if(filename[0..0]!="/")
			filename="/" + (string)this_player()->query_path()
				+ "/" + filename;
		text=read_file(filename);
		if(!text)
			write("No such file.\n" + line + ">>");
		else {
			new_text+=text;
			line+=sizeof(explode(text, "\n"))-1;
			write(text);
			write(line + ">>");
		}
		input_to("get_msg");
		return;
	}
	new_text = new_text + str + "\n";
	line++;
	write(line + ">>");
	input_to("get_msg");
}

read_msg(what_msg) {
	int note;
	if (!what_msg) return 0;
	if (!sscanf(what_msg, "%d", note))
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("Not that many messages.\n");
		return 1;
	}
	note -= 1;
	/*
	say(this_player()->query_name() + " reads a note titled '" +
		headers[note] + "'.\n");
	*/
	write("The note is titled '" + headers[note] + "':\n\n");
#if 0
	printf("%-=78s",messages[note]);
#else
	this_player()->more_string(sprintf("%-=78s", messages[note]));
#endif
	return 1;
}

remove_msg(what_msg) {
	string player, title, date;
	int note, ind;
#if 0
        int ok,i; /* Kelly  see below */
#endif
	if (!what_msg) return 0;
	if (!sscanf(what_msg, "%d", note)) 
		if (!sscanf(what_msg, "note %d", note))
			return 0;
	if (note < 1 || note > msg_num) {
		write("That message doesn't exist.\n");
		return 1;
	}
	note -= 1;
	if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
		error_log("Header error");
		write("Board : error - header corrupt.\n");
		return 1;
	}
        /* 921113 - the guildmaster should be able to remove notes from */
        /* their boards (quick solution)                                */
#if 0
        ok=0;
        for(i=1;i<GM->query_nog();i++)
          ok = ok || this_player()->query_real_name()==GM->query_wiz(i);
#endif
	if (this_player()->query_real_name() != lower_case(player) &&
       this_player()->query_real_name()!=creator(this_object()) &&
       member_array(this_player()->query_real_name(),USERS)==-1 &&
       this_player()->query_level() < 40)
      {
         write("You can't delete a note on the Guildboard.\n");
		   return 1;
	    }
	ind = note;
	while (ind < msg_num - 1) {
		messages[ind] = messages[ind + 1];
		headers[ind] = headers[ind + 1];
		ind++;
	}
	messages[ind] = 0;
	headers[ind] = 0;
	msg_num -= 1;
	save_board();
	write("Ok.\n");
	return 1;
}

store_msg(str) {
	int note;
	string file;
	if (!str) 
		return 0;
	if (sscanf(str, "%d %s", note, file) != 2)
		if (sscanf(str, "note %d %s", note, file) != 2)
			return 0;
	if (note < 1 || note > msg_num) {
		write("That message doesn't exist.\n");
		return 1;
	}
	note -= 1;
	file = file + ".note";
	write_file(file, headers[note] + "\n" + messages[note] + "\n");
	return 1;
}

save_board() {
	int ind;
	ind = 1;
	tmp_head = implode(headers, "\n**\n") + "\n**\n";
	tmp_text = implode(messages, "\n**\n") + "\n**\n";
	save_object(file);
	tmp_head = "";
	tmp_text = "";
	return 1;
}


error_log(str) {
	tell_room(environment(this_object()), "Board says '" + str + "'.\n");
	log_file(ERROR_LOG, file+" : " + str);
	return;
}
query_name()
{
    return short();
}
