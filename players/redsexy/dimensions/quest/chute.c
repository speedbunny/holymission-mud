string type;

id(arg) {
  return arg == type + "chute";
}

get() { return 1; }
drop() { return 1; }

set_type(arg) {
  type = arg;
  return 1;
}
