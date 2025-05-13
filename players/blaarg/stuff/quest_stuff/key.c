inherit "obj/key";
id(str) { return str=="key"||str=="copper key"||str=="clawkey";}

reset(arg) {
string str;
  if (!arg) {::reset(arg);}
}

short() { return "A copper key";}
 
long() { write("A little copper key that seems to fit somewhere in RANMALAND.\n");}
 
query_value() {return 1;}
get() {return 1; }

give() {
  write("The key loses it's magical power and crumbles to dust.\n");
  destruct(this_object());
  return 1;
}

put() { 
  write("The key loses it's magical power and crumbles to dust.\n");
  destruct(this_object());
  return 1;
}
