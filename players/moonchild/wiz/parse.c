#define P "/players/moonchild/wiz/parse_tmp.c"

void init() {
  add_action("parse", "parse");
}

string short() {
  return "Parse tool";
}

void long() {
  write("Usage: parse <lpc code>\n");
}

status id(string str) {
  return str=="parse" || str=="tool" || str=="parsetool" || str=="parse tool";
}

status get() {
  return 1;
}

status drop() {
  return 1;
}

string query_auto_load() {
  return "players/moonchild/wiz/parse:";
}

status parse(string str) {
  mixed res;
  string err;
  object ob;
  if(!interactive(this_player())
	|| (string)this_player()->query_real_name()!="moonchild")
    return 0;
  if(file_size(P))
    rm(P);
  if(ob=find_object(P))
    destruct(ob);
  write_file(P, "parse_it() { return " + str + " }\n");
  if(err=catch(res=P->parse_it()))
    write(err);
  else {
    write("Got");
    write(intp(res) ? " int: " : ": ");
    write(res);
    write("\n");
  }
  return 1;
}
