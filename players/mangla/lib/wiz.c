#include "/sys/defs.h"

int main(string str) {

  if (!str) {
    write("On the wizline:\n\n");
    return CD->print_line(-1);
  }

  if (str=="on" || str=="off") {
    CD->set_line(TP,-1,str=="on"?1:0);
    return 1;
  }

  str="[wiz] "+CAP(TP->RNAME) +
                 (query_verb()=="wiz" ? " says: " : " ") + str + "\n";
  CD->do_chat(-1,str);

  return 1;
}

