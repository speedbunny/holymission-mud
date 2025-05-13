string *pfile;
int id(string str) {
  return str=="relitester" || str=="cross";
}

string short() {
  if(!this_player()->query_immortal()) return "A black cross";
  return "A religion tester";
}

void long() {
  if(!this_player()->query_immortal())
    printf("A black cross, very hot to the touch.\n");
  else printf("A religion tester. Use 'relitest'.\n");
}

int get() { return 1; }
int drop() { return 1; }

void init() {
  if(!this_player()->query_immortal()) {
    printf("The black cross burns to ashes in your hands. Ouch!\n");
    destruct(this_object());
    return;
  }
  add_action("relitest", "relitest");
}

int relitest(string str) {
object *u;
object pl;
  if(!str) str="all";
  if(str == "all") {
    u = users();
    map_array(u, "print_reli", this_object());
    return 1;
  }
  pl = find_player(lower_case(str));
  if(!pl &&
    file_size("/p/"+str[0..0]+"/"+str+".o") == -1) {
    notify_fail("No such player in the Holy Mission.\n");
    return 0;
  }
  if(pl) {
    printf("%s is a follower of %s\n", pl->query_short_name(),
      pl->query_religion());
    return 1;
  }
  pfile=explode(read_file("/p/"+str[0..0]+"/"+str+".o"),"\n");
  filter_array(pfile, "find_reli", this_object(), str);
  return 1;
}

void print_reli(object pl) {
  if(!environment(pl)) return;
  printf("%-12s is a follower of %s\n", pl->query_short_name(),
    pl->query_religion() ? pl->query_religion() : "no one");
}

void find_reli(string line, string name) {
  string reli;
  if(sscanf(line, "religion \"%s\"", reli) == 1)
    printf(capitalize(name)+" is a follower of %s\n", reli);
}

query_pfile() { return pfile; }
