
/*
Tech's room maker

This is a code generator for LPC,
it will intercatively create and edit rooms for LPMud and
makes the routine task of creating rooms much simpler
This program was crated by Tech in Gensesis the original LPMud
also known as Anders Ripa email: ripa@cd.chalmers.se

*/

#include "debug.h"

#define	VERSION		"101"
#define	VERSION_DATE	"901026"


string	short_string;
string	long_text;
string	old_long_text;
string	room_light;
string	out_file_name;
string	out_file_name_c;
int	dir_cnt;
object	dir_array;


int	in_edit;

make(str)
{
	string	temp1, temp2;

	if(!str) {
		write("usage: make filename\n");
		write("Creates a file in your home directory that is a room.\n");
		write("do \"help room maker\" to get more information\n");
		return 1;
	}

	if(sscanf(str, "%s.%s", temp1, temp2) > 0) {
		write(". and .. is not allowed in filenames!\n");
		return 1;
	}

	in_edit = 0;	/* not currently editing */

	out_file_name = "/players/" + this_player()->query_real_name() + "/" + str ;
	out_file_name_c = out_file_name + ".c";

	if(file_size(out_file_name_c) >=0 ) {
		write("Warning! Overwrite existing file " + out_file_name_c + " ?");
		input_to("check_file_ok");
		return 1;
	}
	room_light = 1;
	short_string = "A room";
	write("Short name of room(" + short_string + "):");
	input_to("set_short");
	return 1;
}

check_file_ok(str)
{
	object	ob, temp_dir;
	int	i;

	if(str) {
		str = lower_case(str);
	} else {
		str = "";
	}
	if(str == "y" || str == "yes") {

		call_other(out_file_name, "???");	/* force a load */
		ob = find_object(out_file_name);
		if(ob) {
			if(ob->room_is_modified()) {
				write("This room is modified and may not be changed by the room maker,\ninformation would be lost.\n");
				return 1;
			}
			short_string = ob->short();
			long_text = ob->query_long();
			temp_dir = ob->query_dest_dir();
			if(!long_text && !temp_dir) {
				write("This room is not room maker compatible, and information would be lost.\n");
				return 1;
			}
			if(!dir_array) {
				dir_cnt = 0;	/* start wit the first direction command */
				dir_array = allocate(40);	/* up to 20 command/room pairs (exits) */
			} else {
				i = 0;
				while(i < sizeof(dir_array)) {
					dir_array[i] = 0;
					i += 1;
				}
			}
			i = 0;
			while(i < sizeof(temp_dir)) {
				dir_array[i] = temp_dir[i];
				if(dir_array[i]) {
					dir_cnt = i+1;
				}
				i += 1;
			}
			room_light = ob->query_light();
			in_edit = 1;	/* currently editing */
			edit_room();
			return 1;
		} else {
			write("error: couldnt find " + out_file_name + "\n");
		}
		if(!short_string || short_string == "") {
			short_string = "A room";
		}
		write("Short name of room(" + short_string + "):");
		input_to("set_short");
		return 1;
	} else {
		if(str == "n" || str == "no") {
			write("aborted.\n");
			return 1;
		}
		write("Warning! Overwrite existing file " + out_file_name_c + " (y,n) ? ");
		input_to("check_file_ok");
		return 1;
	}
}

set_short(str) {

	if(!str || str == "") {
		str = short_string;
	}
	if(str == "~q") {
		write("aborted.\n");
		return 1;
	}
	short_string = str;
	if(in_edit) {
		edit_room("");
		return 1;
	}
	long_text = 0;
	write("Long description of " + short_string + ": (** to end)\n");
	write("[");
	input_to("set_long");
	return 1;
}

set_long(str)
{
        int     long_ok;
	int	i;

	if(!str) {
		str = "**";
	}
	if(str == "~q") {
		write("aborted.\n");
		return 1;
	}
	if(in_edit && str == "**") {
		if(!long_text) {
			long_text = old_long_text;
		}
		edit_room("");
		return 1;
	}
        if(!long_text && str == "**") {
                long_text = short_string + ".\n";
                long_ok = 1;	/* we have a complete long comment */
        }
        if(str == "**") {
                long_ok = 1;	/* the long comment is fixed */
        }
	if(!long_ok) {
		if(long_text) {
			long_text += (str + "\n");
		} else {
			long_text = (str + "\n");
		}
		write("[");
		input_to("set_long");
		return 1;
	} else {
		if(!dir_array) {
			dir_cnt = 0;	/* start wit the first direction command */
			dir_array = allocate(40);	/* up to 20 command/room pairs (exits) */
		} else {
			if(!in_edit) {
				i = 0;
				while(i < sizeof(dir_array)) {
					dir_array[i] = 0;
					i += 1;
				}
				dir_cnt = 0;	/* start wit the first direction command */
			}
		}
		write("direction " + (1 + dir_cnt/2) + " command (end with **): ");
		input_to("set_dir_cmd");
	}
	return 1;
}

set_dir_cmd(str) 
{
	if(str && str == "~q") {
		write("aborted.\n");
		return 1;
	}
	if(!str || str == "") {
		write("direction " + (1 + dir_cnt/2) + " command (end with **): ");
		input_to("set_dir_cmd");
		/* ok do it again */
		return 1;
	} else {
		if(str == "**") {
			if(in_edit) {
				edit_dirs("");
				return 1;
			}
			write("light level(" + room_light + "): ");
			input_to("set_light_level");
			return 1;
		}
		dir_array[dir_cnt + 1] = str;
		write("roomfile for " + dir_array[dir_cnt + 1] + " : ");
		input_to("set_dir_file");
		return 1;
	}
}

set_dir_file(str) 
{
	if(str && str == "~q") {
		write("aborted.\n");
		return 1;
	}
	if(!str || str == "") {
		write("roomfile for " + dir_array[dir_cnt + 1] + " : ");
		input_to("set_dir_file");
		return 1;
	} else {
		dir_array[dir_cnt] = str;
		dir_cnt += 2;

		if(dir_cnt >= (sizeof(dir_array) + 2)) {
			write("Maximum number of exist reached!\n");
			if(in_edit) {
				edit_dirs("");
				return 1;
			}
			write("light level(" + room_light + "): ");
			input_to("set_light_level");
			return 1;
		}
		if(in_edit) {
			edit_dirs("");
			return 1;
		}
		write("direction " + (1 + dir_cnt/2) + " command (end with **): ");
		input_to("set_dir_cmd");
		return 1;
	}
}

set_light_level(str)
{
	int	level;

	if(str && str == "~q") {
		write("aborted.\n");
		return 1;
	}
	if(!str || str == "") {
		/* keep default value of 1
		room_light = 1;
		*/
	} else {
		if(sscanf(str, "%d", level) != 1) {
			write("light level(1): ");
			input_to("set_light_level");
			return 1;
		}
		room_light = level;
	}
	edit_room("");
	return 1;
}

/* the main edit menu */

edit_room(str)
{
	int	sel;
	int	match;

	in_edit = 1;	/* currently editing */

	if(!str) str = "";

	match = 1;

	if(strlen(str) >= 1) {
		sel = str[0];
		if(sel == 'h') {
			show_help();
			match = 1;
		}
		if(sel == 'q') {
			write("aborted.\n");
			return 1;
		}
		if(sel == 'e') {
			if(do_edit(extract(str, 1))) {
				return 1;
			}
			str = "";
			match = 1;
		}
		if(sel == 'w') {
			do_file();
			return 1;
		}

	}
	if(str == "" || !match) {
		show_room();
		write("w(rite), q(uit), e(edit) <cr> ? h(help)\n");
		write("command: ");
	}
	input_to("edit_room");
	return 1;
}

show_help()
{
	write("edit menu of room maker\n");
	write("q     - exit from room maker without writing file\n");
	write("w     - write file and exit\n");
	write("es   - edit short comment of room\n");
	write("el   - edit long comment of room\n");
	write("ed   - edit direction information\n");
	write("ev   - edit visibility of room (change light)\n");
	write("<cr>  - show room again\n");
	write("?     - this help text\n");
	write("h     - this help text\n");
	return;
}

do_edit(str) {
	int	sel;

	if(strlen(str) >= 1) {
		sel = str[0];
		if(sel == 's') {
			write("Short name of room(" + short_string + "):");
			input_to("set_short");
			return 1;
		}
		if(sel == 'l') {
			old_long_text = long_text;
			long_text = 0;
			write("Long description of " + short_string + ": (** to end, only ** keeps the old long descrption)\n");
			write("[");
			input_to("set_long");
			return 1;
		}
		if(sel == 'v') {
			write("light level(" + room_light + "): ");
			input_to("set_light_level");
			return 1;
		}
		if(sel == 'd') {
			edit_dirs("");
			return 1;
		}
	}
	write("unknow edit parameter: " + str + "\n");
	write("use the \"h\" to get help.\n");
	return 0;
}

int	edit_dir_num;

edit_dirs(str) {
	int	num, sel;

	if(str && str != "") {
		sel = str[0];
		if(sel == 'm') {
			edit_room("");
			return 1;
		}
		if(sel == 'a') {
			if(dir_cnt >= (sizeof(dir_array) + 2)) {
				write("Maximum number of exist reached!\n");
			} else {
				write("direction " + (1 + dir_cnt/2) + " command (end with **): ");
				input_to("set_dir_cmd");
				return 1;
			}
		}
		if(sel == 'h' || sel == '?') {
			help_dirs();
			str = "";
		}
		if(sel == 'c') {
			if(dir_cnt <= 0) {
				dir_cnt = 0;
				write("No exits to change!\nUse \"a\" to add a new exit \n");
			} else {
				if(sscanf(str, "c%d", num) != 1) {
					write("usage: c#\n");
					write("where # is a number " + 1 + "-" + dir_cnt/2 +1 + "\n");
				} else {
					if(num < 1 || num > dir_cnt/2 +1) {
						write("usage: c#\n");
						write("where # is a number " + 1 + "-" + dir_cnt/2 +1 + "\n");
					} else {
						num -= 1;
						num *= 2;
						edit_dir_num = num;
						write("direction " + (1 + edit_dir_num/2) + " command (" + dir_array[edit_dir_num +1 ] + "): ");
						input_to("change_dir");
						return 1;
					}
				}
			}
		}
		if(sel == 'd') {
			if(dir_cnt <= 0) {
				dir_cnt = 0;
				write("No exits to remove!\n");
			} else {
				if(sscanf(str, "d%d", num) != 1) {
					write("usage: d#\n");
					write("where # is a number " + 1 + "-" + dir_cnt/2 +1 + "\n");
				} else {
					if(num < 1 || num > dir_cnt/2 +1) {
						write("usage: d#\n");
						write("where # is a number " + 1 + "-" + dir_cnt/2 +1 + "\n");
					} else {
						num -= 1;
						num *= 2;
						while( (num+2) < sizeof(dir_array) && dir_array[num+2]) {
							dir_array[num] = dir_array[num + 2];
							dir_array[num+1] = dir_array[num + 3];
							num += 2;
						}
						dir_cnt -= 2;
						dir_array[dir_cnt] = 0;
						dir_array[dir_cnt+1] = 0;
					}
				}
			}
		}
	}
	write("---exits---\n");
	show_dirs(1);
	write("c(change)#, d(elete)#, a(dd), ?,  h(elp) m(ain menu)\n");
	write("command: ");
	input_to("edit_dirs");
	return 1;
}

change_dir(str) {
	if(str && str != "") {
		dir_array[edit_dir_num +1] = str;
	}
	write("roomfile for " + dir_array[edit_dir_num + 1] + "(" + dir_array[edit_dir_num] + ") : ");
	input_to("change_room");
	return 1;
}

change_room(str) {
	if(str && str != "") {
		dir_array[edit_dir_num] = str;
	}
	edit_dirs("");
	return 1;
}

help_dirs()
{
	write("direction editor\n");
	write("m    - return to main edit menu\n");
	write("c#   - change direction and room number #\n");
	write("d#   - delete direction number #\n");
	write("a    - add a new direction and room\n");
	write("h    - this help text\n");
	return;
}

show_dirs(arg) {
	int	i;

	i = 0;
	while(i+1 < sizeof(dir_array) && dir_array[i]) {
		if(arg) {
			write((i/2 + 1) + ": ");
		}
		write(dir_array[i+1] + "-> " + dir_array[i] + "\n");
		i += 2;
	}
}

show_room()
{
	write("\n---file name---\n");
	write(out_file_name_c + "\n");
	write("---short description---\n");
	write(short_string + ".\n");
	write("---long description---\n");
	write(long_text);
	write("---exits---\n");
	show_dirs(0);
	write("---other---\n");
	write("light: " + room_light + "\n");
	write("-----------\n");
	return 1;
}

string	file_text;

do_file()
{
	int	i;
	object	longs, ob;
	string	slask;
	int	ret;

	file_text = "";

	add_line("");
	add_line("");
	add_line("inherit \"room/room\";");
	add_line("");
	add_line("reset(arg) {");
	add_line("    if (arg) return;");
	add_line("");
	add_line("    set_light(" + room_light + ");");
	add_line("    short_desc = \"" + short_string + "\";");
	longs = explode(long_text, "\n");
	if(longs) {
		i = 0;
		slask = "\\nx";	/* this is uggly to get a backslash and "n" into the file created */

		add_line("    long_desc = ");
		while(i < sizeof(longs)) {
			add("        ");
			if(i > 0) {
				add("+ ");
			}
			add("\"");
			add(longs[i]);
			add(extract(slask, 0, 0));	/* uggly */
			add("n\"");
			if(i == sizeof(longs)-1) {
				add_line(";");
			} else {
				add_line("");
			}
			i += 1;
		}
			
	}
	add_line("    dest_dir = ");
	add_line("        ({");
	i = 0;
	while(i+1 < sizeof(dir_array) && dir_array[i]) {
		add_line("        \"" + dir_array[i] + "\", \"" + dir_array[i+1] + "\",");
		i += 2;
	}
	add_line("        });");
	add_line("}");

	add_line("");
	add_line("query_light() {");
	add_line("    return " + room_light + ";");
	add_line("}");

	add_line("query_room_maker() {");
	add_line("    return " + VERSION + ";");
	add_line("}");

	add_line("");
	add("/"); add_line("*");
	add_line("    remove the comments around the \"room is modified()\" code");
	add_line("    below to prevent changes you have done to this room to");
	add_line("    to be lost by using the room maker");
	add("*"); add_line("/");

	add("/"); add_line("*");
	add_line("room_is_modified() {");
	add_line("    return 1;");
	add_line("}");
	add("*"); add_line("/");

	add_line("");
	add("/"); add_line("*");
	add_line(" make your additions below this comment, do NOT remove this comment");
	add_line("--END-ROOM-MAKER-CODE--");
	add("*"); add_line("/");
	add_line("");

	if(file_size(out_file_name_c) >= 0) {
		write("Removing existing file " + out_file_name_c + ".\n");
		ret = rm(out_file_name_c);
		if(is_debug) {
			write("rm returned " + ret + "\n");
		}
	}
	write("Creating file " + out_file_name_c + ".\n");
	ret = write_file(out_file_name_c, file_text);
	if(is_debug) {
		write("write_file returned " + ret + "\n");
	}
	write("Updating file " + out_file_name + ".\n");
	ob = find_object(out_file_name);
	if(ob) {
		destruct(ob);
	}
	write("Teleporting to " + out_file_name + ".\n");
	this_player()->move_player("X#" + out_file_name);
	write("Ok.\n");
}

add_line(str) {
	if(is_debug) {
		write("add_line(");
		write(str);
		write(")\n");
	}
	if(file_text == 0) {
		file_text = "";
	}
	file_text = file_text + str + "\n";
}

add(str) {
	if(is_debug) {
		write("add(");
		write(str);
		write(")\n");
	}
	if(file_text == 0) {
		file_text = "";
	}
	file_text = file_text + str;
}

init()
{
	if(
		this_player()
		&&
		environment(this_object()) == this_player()
		&&
		(this_player()->query_level() > 19)
	) {
		add_action("make", "make");
		add_action("debug_toggle", "debug");
		add_action("version", "ver");
		add_action("help", "help");
	}
}

help(arg) {
	if(!id(arg)) {
		return 0;
	}
	write("usage: make filename\n");
	write("Creates a file in your home directory that is a room,\n");
	write("you are then teleported there.\n");
	write("Do not add \".c\" to filename as this is done automatically.\n");
	write("The process can be aborted by entering ~q at any prompt.\n");
	write("More help can be found in the various editing menues with\n");
	write("the ? command.\n");
	write("example: make newroom\n");
	write("         will create a file named /players/xxxx/newroom.c\n");
	write("         where xxxx is your name\n");
	write("example: make room/myplace\n");
	write("         will create a file named /players/xxxx/room/myplace.c\n");
	write("The room maker can edit existing rooms if they were created by\n");
	write("the room maker, just specify an existing room to edit it.\n");
	return 1;
}

version(str) {
	if(!str || !id(str)) {
		return 0;
	}
	write("Tech's room maker version " + VERSION + " created " + VERSION_DATE + "\n");
	return 1;
}

get() {
	return 1;
}

query_name()
{
	return "room_maker";
}

id(str)
{
	return (str == "roommaker" || str == "room maker" || str == "room_maker" || str == "maker");
}

short()
{
	return "A room maker";
}

long()
{
	write("A portable room maker, for lazy wizards...\n");
	write("usage: make roomfilename\n");
	write("Do \"help room maker\n for more information.\n");
	return 1;
}


query_info() {
    return "a powerful magical/technological creation utility. (wiz use only!)";
}

