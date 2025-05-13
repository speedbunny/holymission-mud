#include "/players/nylakoorub/guild/defines.h"
object banish_status;
object gld_status;
object cur_level;
object last_logon;
object last_logoff;
object enter_msg;
object exit_msg;

is_vagbanish(string name) {
    restore_object(INFO + name);
    return banish_status;
}




check_status(string name) {
    restore_object(INFO + name);
    return gld_status;
}


check_current_level(string name) {
    restore_object(INFO + name);
    return cur_level;
}

check_last_logon(string name) {
    restore_object(INFO + name);
    return last_logon;
}


check_last_logoff(string name) {
    retore_object(INFO + name);
    return last_logoff;
}

query_entermsg(string name) {
    restore_object(INFO + name);
    return enter_msg;
}


query_exitmsg(string name) {
    restore_object(INFO + name );
    return exit_msg;
}

set_gld_status(string name, int number) {
    restore_object(INFO + name);
    gld_status = number;
    save_object(INFO + name);
}

set_vagbanish(string name, int number) {
    restore_object(INFO + name);
    banish_status = number;
    save_object(INFO + name);
}



