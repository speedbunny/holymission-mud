 
id (str) { return str=="key" || str=="toilet key" || str=="toiletkey";}
 
short() { return "a magic key";}
 
long() {
    write("This looks like the 'key' to your luck.\n");
}
 
query_value() { return 1; }
query_quest_item() { return 1; }
get() { return 1; }

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
