#define FILE "players/moonchild/gnome/shop/title"

string pret,tit;
int lvl;

int id(string str) {
  return str=="Title";
}

drop() {
  return 1;
}

void initialize() {
  pret=(string)this_player()->query_pretitle();
  if(!pret)
    pret="none";
  tit=(string)this_player()->query_title();
  if(!tit)
    tit="none";
  lvl=(int)this_player()->query_level();
}

void init_arg(string str) {
  sscanf(str, "%s#%s#%d", pret, tit, lvl);
  call_out("set_title", 4, 0);
}

void set_title() {
  if(lvl==(int)this_player()->query_level()) {
    this_player()->set_pretitle(pret);
    this_player()->set_title(tit);
  }
  else
    destruct(this_object());
}

string query_auto_load() {
  return FILE + ":" + pret + "#" + tit + "#" + lvl;
}
