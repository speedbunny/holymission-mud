#include "/sys/defs.h"

int main(string str) {

    object *ob, env, name, obj;
    string *s, st;
    int i,j;

    if (!str) {
        notify_fail("new <string>\n");
        return 0;
    }

    name = TP->RNAME;
    if(str[0] == '~')
        str = "/players/" + name + str[1..strlen(str)-1];
    env = ENV(TP);
    str = "secure/valid"->valid_read(str);
    if (!str) {
        write("Invalid filename.\n");
        return 1;
    }
    ob = all_inventory(TP);
    j = sizeof(ob);
    for (i=0; j; i++) {
        s = explode(file_name(ob[i]),"/");
        st = explode(s[sizeof(s)-1],"#")[0];
        if (st == str || ob[i]->id(str))
            destruct(ob[i]);
    }
    ob = all_inventory(env);
    for (i=0, j=sizeof(ob); i<j; i++) {
        s = explode(file_name(ob[i]),"/");
        st = explode(s[sizeof(s)-1],"#")[0];
        if (st == str || ob[i]->id(str))
            destruct(ob[i]);
    }
    obj = find_object(TP->query_path() + "/" + str);
    if (obj)
        destruct(obj);
    MOVE(obj = clone_object(str),env);
    if (obj->get())
        transfer(obj,TP);
    write("Ok.\n");

    return 1;
}

