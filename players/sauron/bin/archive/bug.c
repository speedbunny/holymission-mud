#include "/sys/bin.h"
#include "/sys/defs.h"

int main(string sStr) {
    string sCreator,sCmd,sName,sLog;

    if(!sStr || sStr=="") {
        notify_fail("Give an argument.\n");
        return 0;
    }
    else {
        sCmd=capitalize(query_verb());
        sName=TP->CRNAME;
        switch(sCmd) {
            case "Bug":
                sLog="BUGS";
                break;
            case "Idea":
                sLog="IDEA";
                break;
            case "Typo":
                sLog="TYPO";
                break;
        }
        log_file(sLog,sprintf("\n%s %s (%s):\n%s\n",
                              sName,ctime(),file_name(ENV(TP)),sStr));
        sCreator=creator(ENV(TP));
        if(sCreator)
            log_file(sCreator+".rep",
                     sprintf("%s: %s\n%s %ss: %s\n",
                             ctime(),file_name(ENV(TP)),
                             sName,lower_case(sCmd),sStr));
        if(sCmd=="Bug" && !TP->IMM && !TP->TESTP)
            CD->do_chat(-3,sprintf("%-*s %-=*s\n",8,"[report]",72,
                                   sprintf("%s bugs: %s",
                                           sName,sStr)));
        write("Thank you!\n");
        return 1;
    }
}

string help() {
    return "\
Command:\tbug\n\
Arguments:\ta bug report.\n\
See also:\tidea, typo"
+(TP->IMM || TP->TESTP?
    ", rep":
    "")+".\n\
\n\
This command logs a bug regarding your current environment, or one of \
the items in it. If you want to report an idea or a typo, please use \
the appropriate command.\n";
}
