#include "/sys/bin.h"
#include "/sys/defs.h"

int main(string sStr) {
    return (PLAYER_BIN+"bug")->main(sStr);
}

string help() {
    return "\
Command:\ttypo\n\
Arguments:\ta typo.\n\
See also:\tbug, idea"
+(TP->IMM || TP->TESTP?
    ", rep":
    "")+".\n\
\n\
This command logs a typo regarding your current environment, or one of \
the items in it. If you want to report a bug or an idea, please use \
the appropriate command.\n";
}
