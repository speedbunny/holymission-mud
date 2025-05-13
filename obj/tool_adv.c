/* 
    This is an advancement-file for the dynion - tool
    it has to be here in the /obj - dir for the file access.

    170298: Sauron: Fixed up the code somewhat. Removed the 'globals' stuff.
            Also now uses std defines in "/include/defs.h". Left the 'got'
            stuff in for now, although I don't see any use for it.
*/

#define TPRN    this_player()->query_real_name()

string got;

static string txt1;
static string txt2;

void set_got(string arg) {
    got = arg;
}

string query_got() {
    return got;
}

void write_got() {
    save_object("/players/"+TPRN+"/dynion_tmp");
}

void rm_got() {
    rm("/players/"+TPRN+"/dynion_tmp.o");
}
 
mixed call_efun(string txt, object m, object s, object l) {
    string fname, err_msg;
    object ef;
    mixed  res;

    fname = "/players/"+TPRN+"/dynion_efun.c";
    if(file_size(fname) >= 0)
        rm(fname);
    write_file(fname, txt1+txt+txt2);
    if(err_msg = catch(ef = fname->query_me())) {
        printf("Error in loading object (%s)\n\n%s%s%s\n\n%s",
               fname, implode(explode(txt1, "\n")[<2..<1], "\n"),
               txt, implode(explode(txt2, "\n")[0..3], "\n"),
               err_msg);
        rm(fname);
    }
    else {
        rm(fname);
        ef->set_marks(m, s, l);
        if(err_msg = catch(res = ef->efunction()))
           printf("Error in calling the efun!\n%s", err_msg);
        else
            got = res;
        destruct(ef);
        return res;
    }
}

void reset(int arg) {
    if(!arg) {
        txt1 = "\
#include <defs.h>\n\
\n\
object mark, spare, last;\n\
mixed  res;\n\
\n\
object query_me() {\n\
   return this_object();\n\
}\n\
\n\
mixed efunction() {\n    ";

      txt2 = "\n\n\
    return res;\n\
}\n\
\n\
void dest_me() {\n\
    destruct(this_object());\n\
}\n\
\n\
void set_marks(object m, object s, object l) {\n\
    mark = m;\n\
    spare = s;\n\
    last = l;\n\
    call_out(\"dest_me\", 2);\n\
}\n";
   }
}
