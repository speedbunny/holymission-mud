int legth;
id(a) { return a=="chalk"; }
short() { return "a piece of chalk"; }
long() { write(capitalize(short())+".\n"); }
get() { return 1; }
query_weight() { return(1); }
query_value() { return(50); }
reset(arg) {
  if(arg) return;
  legth=20;
}
reduce() { 
  legth--;
  if(!legth) {
    write("The chalk is used up now.\n");
    destruct(this_object());
    return;
  }
}
