 
id (str) { return str=="questkey"||str=="iron key"||str=="rusty key"||str=="key";}
 
short() { return "A rusty iron key";}
 
long() { write("A rusty iron key from the witch.\n"+
                "It seems that the witch hadn't used\n"+
                "or cleaned it for weeks.\n"); }
 
query_value() {return 1;}
query_quest_item() {return 1;}

get() {return 1;}

drop() {
  write("Your iron key crumbles to dust.\n");
  destruct(this_object());
  return 1;
}

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
