#include "/players/sauron/secure/include/include.h"

int main(string sStr) {
    string sLwd;

    if(!sStr)
        sStr = "~";
    else if(sStr == "-")
        sStr = TP->queryenv("LWD");
    sLwd = "/"+TP->query_path();
    sStr = expand_filename(sStr);
    if(!sStr)
        return 1;
    else if((int)TP->cd(sStr)) {
        TP->setenv("LWD", sLwd);
        return 1;
    }
    else
        return 0;
}

string help() {
    return "\
Command:\tcd\n\
Arguments:\tnone or a directory.\n\
Examples:\tcd, cd ~sauron, cd /log\n\
See also:\tls, pwd.\n\
\n\
This command sets your current working directory (also called path). \
This path is prepended to file arguments when using other file \
handling commands such as cp, mv and ls.\n";
}
