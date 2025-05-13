int number;
object master;

void reset(int arg) {
  if(arg)
    return;
  master=previous_object();
  enable_commands();
}

int query_npc() {
  return 1;
}

void set_number(int i) {
  number=i;
}

void init() {
  if(!master)
    destruct(this_object());
}

void catch_tell(string str) {
  if(!master)
    destruct(this_object());
  else {
    string junk;
    if(!sscanf(str, "Picture shows%s", junk)) {
      "players/moonchild/cctv/master"->notify(str, number);
    }
  }
}
