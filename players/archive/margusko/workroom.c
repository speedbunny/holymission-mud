#include "params.h"
inherit ROOM;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
set_light(1);
short_desc = "Margusko's workroom.\n";
long_desc =" Welcome to Margusko's workroom ...\n Feel free to find out a better long description.\n";
}

void init() {
    ::init();
   add_action("command_line","",2);
#if 1
    if(lower_case(this_player()->query_real_name()) != "margusko") {
        write(lower_case(this_player()->query_real_name())+"\n");
        write("You are not allowed to use this workroom.\n");
        return;
    }
#endif
}

int command_line(string str) {
    string cmd, arg;
    notify_fail("Command not found.\n");
    if(sscanf(str, "%s %s", cmd, arg) != 2) cmd = str;
    write("Command: "+cmd+", Argument: "+arg+"\n");
    if(cmd == "home") return 0;
    if(file_size(BD+cmd+".c") <1 ) return 0;
    write("Execing\n");
    return call_other(BD+cmd, "cmd_"+cmd, arg);
}
