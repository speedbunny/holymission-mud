#include "/players/gareth/define.h"

id(str) {return str=="book" || str=="notebook"; }
query_name() { return "book"; }
short() { return "A fighters note book"; }
long() { return write("The book is attached to the wall. Just read it.\n"); }
get() { return 0; }

init() {
add_action("read","read");
}

read(arg) {
  if(arg=="book") {
    TP->more(PG+"guild/book.txt");
    return 1;
  }
}
