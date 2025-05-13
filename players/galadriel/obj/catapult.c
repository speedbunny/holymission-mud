#define VER "1.0"
#define PNAME this_player()->query_name()

int number;

id(str) { return str == "catapult"; }

short() { return "A heavy catapult"; }

long()  { 
  write("This is Galadriel's catapult. It is very heavy.\n");
  write("There is an inscription on it.\n");
}

read(arg) {
  if (arg != "inscription") return 0;
  write("This is version "+VER+" of Galadriel's catapult.\n");
  write("It is one of Galadriel's first creations!\n");
  return 1;
}

get()	{ return 0; }

reset(arg) {
  if (arg) return;
  number = 0;
}

init() { 
  add_action("read", "read");
}
