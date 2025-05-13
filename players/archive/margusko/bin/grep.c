//      /bin/system/_grep.c
//      from the CoreDump Mudlib
//      searches for an expression in files
//      created by Descartes of Borg 930822
//      -x feature by Avenger 960125 (midnight)
#include <std.h>
inherit "/players/leslie/functions";
#define message(x, y, z) write(y+"\n")

int cmd_grep(string str) {
    mapping borg;
    string *lines, *files;
    string output, exp, xexp, file, tmp;
    int i, max;

    notify_fail("Correct syntax: <grep '[pattern]' [file] (> [output])>\n");
    if(!str) return 0;
    if(sscanf(str, "%s > %s", tmp, output) == 2) {
	if(output[0] != '/')
	    output = (string)previous_object()->get_path()+"/"+output;
	str = tmp;
    }
    else output = 0;
    if(sscanf(str, "'%s' %s", exp, file) != 2 &&
      sscanf(str, "%s %s", exp, file) != 2) return 0;
    if(sscanf(file,"-x'%s' %s", xexp,tmp)==2 ||
      sscanf(file,"-x%s %s",xexp,tmp)==2)
    {
	file=tmp;
	write("Exchanging "+exp+" to "+xexp);

	xexp=replace_string(xexp,"\\n","\n");
    }
    else xexp=0;
if(!(max = sizeof(files = wild_card(file))))
    { 
write("File not found.\n");
	return 1;
    }
    for(i=0, borg = ([]); i<max; i++)
    {
	if(file_size(files[i])>0)
	{
	    borg[files[i]] = regexp(explode(tmp=read_file(files[i]), "\n"), exp);
	    if(!sizeof(borg[files[i]])) m_delete(borg, files[i]);
	    if(xexp) write_file(files[i],replace_string(tmp,exp,xexp));
	}
    }
    if(!(max = sizeof(files = m_indices(borg)))) str = "No matches found.\n";
    else {
	for(i=0, str = ""; i<max; i++)
	    str += sprintf("%s:\n%s\n\n", files[i], implode(borg[files[i]],"\n"));
    }
    if(output) {
	if(!write_file(output, str)) 
	    message("system", "Failed to write to: "+output, this_player());
	else message("system", "Grep sent to: "+output, this_player());
    }
    else message("Nsystem", str, this_player());
    return 1;
}

void help() {
    message("help",
      "Syntax: <grep '[pattern]' (-x'pattern') [file] (> [redirect])>\n\n"
      "Searches a file or group of files for a specific pattern.  "
      "You can replace it with the pattern marked by -x. "
      "If the pattern is a single word, then no '' is needed.  Patterns "
      "of more than one word however, need to be enclosed in ''.  "
      "You may redirect the output of the grep to a file using the >."
      "(And you may thank it to Avenger :) "
      "\n\nSee also: cd, ls, mv, pwd, rm", this_player()
    );
}
