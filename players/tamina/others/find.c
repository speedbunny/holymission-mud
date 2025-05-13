inherit "obj/thing";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("wizfinder");
  set_alt_name("black box");
  set_alias("box");
  set_short("A black box");
  set_long("A wizfinder tool. Use 'wizfind'.\n");
  set_value(0);
  set_weight(0);
  }

void init() {
  ::init();
  if(this_player()->query_immortal()) add_action("wizfind", "wizfind");
  }

int wizfind() {
object *u;
int i;
  u = filter_array(users(), "wiz_filter", this_object());
  map_array(u, "print_loc", this_object());
  i = sizeof(u);
  printf("There %s %d %s logged in.\n", i==1 ? "is" : "are",
    i, i==1 ? "wizard" : "wizards");
  return 1;
}

int wiz_filter(object pl) {
  return pl->query_immortal();
}

string get_lvl(object wiz) {
  switch(wiz->query_level()) {
    case 30:   return "Ap";
    case 31:   return "Nw";
    case 33:   return "Wz";
    case 35:   return "Sr";
    case 36:   return "Rt";
    case 40:   return "Ld";
    case 50:   return "Ar";
    case 500:  return "hA";
    case 1000: return "Gd";
    default:   return "??";
  }
}

void print_loc(object wiz) {
  string *fname, modname;
  if(!environment(wiz)) return;
  fname = explode(file_name(environment(wiz)), "/");
  if(fname[0] == "players") {
    if(fname[1] == wiz->query_real_name()) {
      if(fname[2] == "workroom") modname = "home";
      else {
        fname = del_array(fname, 0);
        fname[0] = "~";
        modname = implode(fname, "/");
      }
    }
    else {
      fname[0] = "&";
      modname = implode(fname, "/");
    }
  }
  else modname = implode(fname, "/");
  printf("[%s] %-10.10s is at %-25.25s and idle for %4d seconds.\n",
    get_lvl(wiz), wiz->query_short_name(), modname, query_idle(wiz));
}

void long() {
  if(this_player()->query_real_name() != "topaz")
    printf("A black box. There's a dangerous aura about it.\n");
  else printf("A wizfinder tool. Use <wizfind>.\n");
}

drop() { return 1; }

string query_auto_load() {
  return "players/topaz/tools/finder:";
}
