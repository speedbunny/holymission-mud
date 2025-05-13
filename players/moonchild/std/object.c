inherit "players/moonchild/std/property";

status id(string str) {
  if(str==(string)query("name")) return 1;
  if(pointerp(query("aliases")))
    return member_array(str, query("aliases"))!=-1;
}

string short() {
  return (string)query("short");
}

void long() {
  write((string)query("long"));
}

void init() {
  if(query("read_msg"))
    add_action("read", "read");
}

status get() {
  return 1;
}

int query_value() {
  return (int)query("value");
}

int query_weight() {
  return (int)query("weight");
}

string query_name() {
  return (string)query("name");
}

status read(string str) {
  if(!id(str) || !query("read_msg")) return 0;
  write((string)query("read_msg"));
  return 1;
}
