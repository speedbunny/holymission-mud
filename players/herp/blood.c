
id(str) { return str=="blood"; }

init() { add_action("blood","blood"); }

blood(string name) {
string s;
object ob;

  ob=find_player(name);
  if (!ob) return 0;

  tell_object(ob,"Someone utters the words, 'bloodrush'\n");
  s=sprintf("%c[41m%c[31m%c[0J",27,27,27);
  tell_object(ob,s);
  return 1;
}
