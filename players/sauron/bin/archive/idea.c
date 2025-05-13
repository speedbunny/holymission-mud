#include "/sys/bin.h"
#include "/sys/defs.h"

int main(string sStr) {
    return (PLAYER_BIN+"bug")->main(sStr);
}

string help() {
    return "\
Command:\tidea\n\
Arguments:\tan idea.\n\
See also:\tbug, typo"
+(TP->IMM || TP->TESTP?
    ", rep":
    "")+".\n\
\n\
This command logs an idea regarding your current environment, or one of \
the items in it. If you want to report a bug or a typo, please use \
the appropriate command.\n";
}
