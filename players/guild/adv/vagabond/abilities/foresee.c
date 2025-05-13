#include "lw.h"
#include "/players/nylakoorub/guild/defines.h"
string *cmds,mov;
object obj;



/* Predeclaration of functions. */
int output();
int exp_dirs(string arg);

int main(string str) {
    string *dirs,*tmp,s2,file;
    int t,pos,s1;
    CG;
    cmds = dirs = tmp = ({});
    mov = "";
    if (!str) {
	write("Usage: foresee <direction(s)>\n");
	return 1;
    }
    tmp = explode(str,",");
    for (t = 0; t < sizeof(tmp); t++) {
	if (sscanf(tmp[t],"%d %s",s1,s2) == 2)
	    exp_dirs(tmp[t]);
	else { 
	    switch(tmp[t]) {
	    case "n": cmds += ({"north"}); break;
	    case "ne": cmds += ({"northeast"}); break;
	    case "e": cmds += ({"east"}); break;
	    case "se": cmds += ({"southeast"}); break;
	    case "s": cmds += ({"south"}); break;
	    case "sw": cmds += ({"southwest"}); break;
	    case "w": cmds += ({"west"}); break;
	    case "nw": cmds += ({"northwest"}); break;
	    case "d": cmds += ({"down"}); break;
	    case "u": cmds += ({"up"}); break;
	    default: cmds += ({tmp[t]}); break;
	    }
	}
    }
    obj = environment(this_player());
    for (t = 0; t < sizeof(cmds); t++) {
	dirs = (string *)obj->query_room("dest_dir");
	if(catch(member_array(cmds[t],dirs))){
	    write("You can not foresee into that place!\n");
	    return 1;
	}
	pos = member_array(cmds[t], dirs);
	if (pos == -1 && t+1 != sizeof(cmds)) {
	    mov += "*"; 
	} else if (pos != -1) {
	    mov += "->";
	    file = dirs[pos-1];
	    if (sscanf(dirs[pos-1],"%s.c",s2) != 1)
		file += ".c";
	    call_other(file,"???");
	    obj = find_object(file);
	} else {
	    if (present(cmds[t],obj))
		obj = present(cmds[t],obj);
	    else 
		mov += "*";
	}
    }
    output();
    return 1;
}
int output() {
    int t;
    string *dirs;
    object *items;
    dirs = ({});
    write(mov+"\n");
    write("You can foresee:\n");
    say(lw(this_player()->query_name()+" closes "+
	this_player()->query_possessive()+" eyes and when "+
	this_player()->query_pronoun()+" opens it again "+
	this_player()->query_pronoun()+" has a distant look.\n"));
    t = (int)obj->long();
    if (living(obj) && all_inventory(obj))
	write("    "+obj->query_name()+" is carrying:\n");
    if (all_inventory(obj)) {
	items = all_inventory(obj);
	t = 0;
	while (t < sizeof(items)) {
	    if (items[t]->query_invis() == 0 && items[t]->short())
		write(items[t]->short()+"\n");
	    t++;
	}
    }
    return 1;
}
int exp_dirs(string arg) {
    int ant,t;
    string dir;
    sscanf(arg,"%d %s",ant,dir);
    switch(dir) {
    case "n": dir = "north"; break;
    case "ne": dir = "northeast"; break;
    case "e": dir = "east"; break;
    case "se": dir = "southeast"; break;
    case "s": dir = "south"; break;
    case "sw": dir = "southwest"; break;
    case "w": dir = "west"; break;
    case "nw": dir = "northwest"; break;
    case "d": dir = "down"; break;
    case "u": dir = "up"; break;
    }
    for (t=0;t < ant;t++) {
	if (!cmds)
	    cmds = ({dir});
	else
	    cmds += ({dir});
    }
    return 1;
}
query_cmds() {
    return cmds;
}


