 
id (str) { return str=="key"||str=="iron key"||str=="witchkey";}
 
short() { return "A polished iron key";}
 
long() { return short()+".\n"; }
 
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
