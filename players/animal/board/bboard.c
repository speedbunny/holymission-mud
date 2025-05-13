/* Chez B-board!   chezbboard.c */
 
/* Modifications by Lars Huttar of Swat mud, 4/91:
     Expiration after 30 days, note is removed and written to file.
        You can also voluntarily expire your notes.
     Fixed paren-parsing bug by keeping track of name and time separately
        from header.
     No more notes from 'Someone'.  query_real_name() is used in header.  Old
        notes from 'Someone' (from previous versions) can be removed by anyone.
     Conversion program wbconverter.c converts from old style to this style.
     Setable save file and expiration file; this means that you can make as
        many separate bulletin boards as you want from this one source file.
        These files should be set right after the board is cloned;
        the board's messages will be read in from save_file as soon as
        someone accesses the board.
        Both filenames should be absolute, but without initial '/'.
     Other setable parameters (optional):
        set_short(str)   <==  short description, e.g. "Mage guild board"
        set_min_level(n) <==  minimum level allowed to post, e.g. 20
        set_verbose(1)   <==  give ugly debugging output
     Separate usage help with "help bboard".  (No longer in long().)
     "titles" command lists last n messages or messages starting at n.
 */
 
/* Groo 90-12-02 */
/**********************************
 * The new, great bulletin board! *
 * (The manic wanderer - version) *
 * (with the nasty bug #1 fixed.) *
 **********************************/
 
#define ERROR_LOG "CHEZBBOARD.ERROR"
/* The next two are defaults; save_file and expire_file must be set
   after creation with set_save_file and set_expire_file.  That way you
   can have different instances of the bulletin board, with different
   save files, but the board object are both cloned from the same file. */
#define SAVE_FILE ""
#define EXPIRE_FILE ""
#define EXPIRE_DAYS 30
#define MAX_NOTES 40
 
 
static string new_head, new_text;
 
string tmp_head, tmp_text, tmp_auth, tmp_time;
int msg_num;
 
/* Headers will still contain name and date, for efficiency's sake;
   but now this info will also be stored in authors[i] and times[i]. -Lars */
 
static string save_file, expire_file, short_desc;
static string  messages, headers, authors;
static int line, restored_yet, times, min_level;
static object curr_writer;
static status verbose;
 
id(str) {
        return (str == "board" || str == "bulletin board" ||
                str == "chezbboard" ||
                str == "bulletinboard" || str == short_desc);
}
 
long() {
        int ind;
 
        maybe_restore_board();
 
        write("This is "+short()+".\n");
        write("Type `help bboard' for instructions.\n");
 
        if (!msg_num) {
                write("The board is empty.\n");
                return;
        }
        write("The bulletin board contains " + msg_num);
        if (msg_num == 1)
                write(" note :\n\n");
        else
                write(" notes :\n\n");
 
        if (verbose)
           say(this_player()->query_name() + " studies the bulletin board.\n");
 
        for (ind = 0; ind < msg_num; ind++)
           write(right_justify(ind+1, 3) + ": " + headers[ind] + "\n");
}
 
help_bboard(str) {
   if (str != "bboard") return 0;
 
   write("Usage : note <title>       --- post a note with this title.\n");
   write("        titles <num>       --- list titles starting with <num>.\n");
   write("        titles -<num>      --- list last <num> titles.\n");
   write("        read <num>         --- read message number <num>.\n");
   write("        remove <num>       --- remove message <num>.\n");
   if (this_player()->query_level() >= 20)
      write("        store <num> <file> --- write message in a file.\n");
   write("        expire <num>       --- remove and archive.\n");
 
   write("\nAfter " + EXPIRE_DAYS + " days, old messages get removed " +
         "automatically\nand are ");
   if (expire_file == "" || this_player()->query_level() < 20)
      write("archived.\n");
   else write("written to the file " + expire_file + ".\n");
 
   if (min_level > 1)
      write("\nYou must be at least level " + min_level + " to");
   else write("\nAnyone may");
   write(" post or remove notes here.\n");
   return 1;
}
 
short() {
        return short_desc;
}
 
get() {
        write("It is firmly secured to the ground.\n");
        return 0;
}
 
set_save_file(str) {
   save_file = str;
   if (!expire_file || expire_file == "")
      expire_file = str + "_exp";  /* Convenient default. */
   return 1;
}
 
set_expire_file(str) {
   expire_file = str;
   return 1;
}
 
/* 1 == verbose, 0 == not verbose */
/* Verbosity is ugly, useful only for debugging. */
set_verbose(mode) {
   verbose = mode;
   return 1;
}
 
set_short(str) {
   short_desc = str;
}
 
/* min_level is minimum level necessary to post/remove/expire. */
 
set_min_level(lvl) {
   /* Discourage cheating... */
   /* I can't think of a way to make this completely secure, but it's
      not a big deal. */
   if (!this_player() || this_player()->query_level() >= min_level)
      min_level = lvl;
   return 1;
}
   
init() {
        add_action("new_msg", "note");
        add_action("read_msg", "read");
        add_action("remove_msg", "remove");
        if (this_player() && this_player()->query_level() >= 20)
           add_action("store_msg", "store");
        add_action("expire_msg", "expire");
        add_action("list_msg", "titles");
        add_action("help_bboard", "help");
}
 
reset(arg)
{
        if (!arg) {
           save_file = SAVE_FILE;
           expire_file = EXPIRE_FILE;
           verbose = 0;
           restored_yet = 0;
           short_desc = "a bulletin board";
           min_level = 0;
           return;
        }
 
        if (!random(5)) {
                        say("A small gnome appears and secures some " +
                        "notes on the board that were loose.\n");
                        say("The gnome leaves again.\n");
        }
 
        check_expire();
}
 
check_expire() {
        int ind, exptime;
        int anyexpired;
 
        maybe_restore_board();
 
        exptime = time() - (EXPIRE_DAYS*24*3600);
 
        if (verbose)
           write("Exptime is " + exptime + " = " + ctime(exptime) + "\n");
 
        /* Notes created before exptime have expired by now. */
 
        anyexpired = 0;
 
        for (ind = 0; ind < msg_num; ind++) {
                if (verbose) {
                   write("Checking note "+ind+" of "+msg_num+".\nwhose time");
                   write(" is "+times[ind]+" = "+ctime(times[ind])+"\n");
                }
                if (times[ind] < exptime) {
                        /* remove note and append to file */
                        write_file("/"+expire_file,
                                   headers[ind] + "\n"+ messages[ind] + "\n");
                        say("A note titled '" + headers[ind] + "'\n" +
                            "expires.  Poof!\n");
                        write("A note titled '" + headers[ind] + "'\n" +
                            "expires.  Poof!\n");
                        delete_note(ind);
                        anyexpired = 1;
                        break;
                        /* I have made this so that only one note expires
                           per reset.  This is to avoid "Too long evalation"
                           errors. */
 
                        /* ind--;  /* Do this if you want to keep looping
                           because the following notes have moved up a notch */
                }
        }
 
        if (anyexpired) save_board();
}
 
new_msg(msg_head) {
 
        maybe_restore_board();
 
        if (this_player()->query_level() < min_level) {
           write("You aren't allowed to post on this board.\n");
           return 1;
        }
 
        line = 1;
        if (!msg_head)
                return 0;
        if (curr_writer && environment(curr_writer) ==
                environment(this_object())) {
                write(this_player()->query_name() + " is busy writing.\n");
                return 1;
        }
        if (msg_num >= MAX_NOTES) {
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
                headers[msg_num] = new_head +
                        "(" + capitalize(this_player()->query_real_name()) +
                        ", " + extract(ctime(time()), 4, 9) +
                        ", " + this_player()->query_level() + ")";
                messages[msg_num] = new_text + "\n";
               authors[msg_num] = capitalize(this_player()->query_real_name());
                times[msg_num] = time();
                msg_num++;
                save_board();
                write("Ok.\n");
                curr_writer = 0;
                return;
        }
        new_text = new_text + str + "\n";
        line++;
        write(line + ">>");
        input_to("get_msg");
}
 
read_msg(what_msg) {
        int note;
 
        maybe_restore_board();
	if(!what_msg) return 0;
 
        if (!sscanf(what_msg, "%d", note))
                if (!sscanf(what_msg, "note %d", note))
                        return 0;
        if (note < 1 || note > msg_num) {
                write("That message doesn't exist.\n");
                return 1;
        }
        note -= 1;
        if (verbose)
            say(this_player()->query_name() + " reads a note titled '" +
                headers[note] + "'.\n");
        write("The note is titled '" + headers[note] + "':\n\n");
        write(messages[note]);
        return 1;
}
 
/* This funtion defines whether this_player() can remove/expire note
   note_num. */
can_touch(note_num) {
   return
      ((authors[note_num] == "Someone" ||
        capitalize(this_player()->query_real_name()) == authors[note_num] ||
        this_player()->query_level() >= 24) &&
       query_ip_number(this_player()) &&
       this_player()->query_level() > min_level);
}
 
remove_msg(what_msg) {
        int note, ind;
 
        maybe_restore_board();
 
        if (!sscanf(what_msg, "%d", note) &&
            !sscanf(what_msg, "note %d", note))
                        return 0;
        if (note < 1 || note > msg_num) {
                write("That message doesn't exist.\n");
                return 1;
        }
        note -= 1;
 
/*
        * This is how the author used to be extracted. *
        if (sscanf(headers[note], "%s(%s,%s", title, player, date) != 3) {
                error_log("Header error");
                write("Board : error - header corrupt.\n");
                return 1;
        }
*/
        if (!can_touch(note)) {
                write("You aren't allowed to remove that note.\n");
                if (verbose)
                   say(this_player()->query_name() + " failed to remove " +
                        "a note.\n");
                return 1;
        }
        say(this_player()->query_name() + " removes a note titled '" +
                headers[note] + "'.\n");
        delete_note(note);
        save_board();
        write("Ok.\n");
        return 1;
}
 
/* delete_note(number) deletes a note by moving all the notes after it
   up one notch.  This function also decrements msg_num.  It does *not*
   save the board. */
 
delete_note(note) {
        while (note < msg_num - 1) {
                messages[note] = messages[note + 1];
                headers[note] = headers[note + 1];
                authors[note] = authors[note + 1];
                times[note] = times[note + 1];
                note++;
        }
        msg_num -= 1;
        return 1;
}
 
store_msg(str) {
        int note;
        string file;
 
        maybe_restore_board();
 
        if (!str ||
            (sscanf(str, "%d %s", note, file) != 2 &&
            (sscanf(str, "note %d %s", note, file) != 2)))
               return 0;
        if (note < 1 || note > msg_num) {
                write("That message doesn't exist.\n");
                return 1;
        }
        note -= 1;
        /* I guess the following line is to prevent players overwriting
           files they're not supposed to? */
        file = file + ".note";
        write_file(file, headers[note] + "\n" + messages[note] + "\n");
        return 1;
}
 
save_board() {
        tmp_head = implode(headers, "\n**\n") + "\n**\n";
        tmp_text = implode(messages, "\n**\n") + "\n**\n";
        tmp_auth = implode(authors, "\n**\n") + "\n**\n";
        /* implode() won't work here because it only likes strings. */
        tmp_time = number_implode(times, "\n**\n") + "\n**\n";
        save_object(save_file);
        tmp_head = "";
        tmp_text = "";
        tmp_auth = "";
        tmp_time = "";
        return 1;
}
 
number_implode(array, str) {
   int i, s;
   string answer;
 
   s = sizeof(array);
   answer = "";
   for (i=0; i<s; i++)
   {
      answer += array[i];
      if (i < s-1) answer += str;
   }
   return answer;
}
 
error_log(str) {
        tell_room(environment(this_object()), "Board says '" + str + "'.\n");
        log_file(ERROR_LOG, "Board : " + str + "\n");
        return;
}
 
/* This function restores the board if it hasn't been restored already. */
maybe_restore_board() {
        int i;
        string arr;
 
        if (restored_yet) return;
 
        if (save_file == "") {
           error_log("Board's save file hasn't been set.  Notify wizard.");
           return;
        }
 
        messages = allocate(MAX_NOTES);
        headers = allocate(MAX_NOTES);
        authors = allocate(MAX_NOTES);
        times = allocate(MAX_NOTES);
        if (!restore_object(save_file)) {
                error_log("Can't restore board from file " + save_file);
                return 1;
        }
 
        restored_yet = 1;
 
        arr = explode(tmp_head, "\n**\n");
        for (i=0; i < msg_num; i++)
                headers[i] = arr[i];
 
        arr = explode(tmp_text, "\n**\n");
        for (i=0; i < msg_num; i++)
                messages[i] = arr[i];
 
        if (msg_num > 0 && (!tmp_auth || tmp_auth == "")) {
                /* restoring from an old-style save file */
                error_log("Old-style save file!  Use wbconvert on the save" +
                          " file before running this board.");
                return;
        }
 
        arr = explode(tmp_auth, "\n**\n");
        for (i=0; i < msg_num; i++)
                authors[i] = arr[i];
 
        arr = explode(tmp_time, "\n**\n");
        for (i=0; i < msg_num; i++) {
                if (sscanf(arr[i], "%d", times[i]) != 1)
                        error_log("Corrupt time "+arr[i]+" on note "+i+".");
                if (verbose)
                  write("Note "+i+": string ["+arr[i]+"] time "+times[i]+"\n");
        }
 
        tmp_text = "";
        tmp_head = "";
        tmp_auth = "";
        tmp_time = "";
 
        return 1;
}
 
expire_msg(what_msg)
{
   int gender, note;
 
   maybe_restore_board();
 
   if (!what_msg) return 0;
   if (!sscanf(what_msg, "%d", note) &&
       !sscanf(what_msg, "note %d", note))
      return 0;
   if (note < 1 || note > msg_num) {
      write("That message doesn't exist.\n");
      return 1;
   }
   note -= 1;
   if (!can_touch(note)) {
      write("You aren't allowed to expire that note.\n");
      if (verbose)
         say(this_player()->query_name() + " failed to expire note" + note + 
             ".\n");
      return 1;
   }
 
   /* remove note and append to file */
   say(this_player()->query_name() + " expires a note titled:\n" +
       headers[note] + "\n");
   write_file("/"+expire_file, headers[note] + "\n"+ messages[note] + "\n");
   delete_note(note);
   write("A little gnome appears from behind the board.\n\"Thank you, noble ");
   gender = this_player()->query_gender();
   if (gender == 1) write("sir"); else if (gender == 2) write("lady");
   else write("creature");
   write(", for freeing up board space.\"\n");
   write("The gnome bows gracefully and disappears behind the board.\n");
   save_board();
   return 1;
}
 
/* titles n    -- list messages starting at n.
   titles -n   -- list last n messages.
*/
list_msg(str) {
   int start, ind;
   status last;
 
   if (!str) {
      long();
      return 1;
   }
 
   maybe_restore_board();
 
   last = 0;
   if (sscanf(str, "-%d", start) == 1) last = 1;
   else if (sscanf(str, "%d", start) != 1)
      return 0;
 
   if (start < 1 || start > msg_num) {
      write("That message doesn't exist.\n");
      return 1;
   }
   start -= 1;
 
   if (last) start = msg_num - 1 - start;
 
   for (ind = start; ind < msg_num; ind++)
      write(right_justify(ind+1, 3) + ": " + headers[ind] + "\n");
 
   return 1;
}
 
/* A specialized right_justify; works only for minwidth < 6. */
right_justify(num, minwidth) {
   string ans;
 
   ans = num + "";
   if (strlen(ans) < minwidth)
      ans = extract("     ", 1, minwidth - strlen(ans)) + ans;
   return ans;
}
 
