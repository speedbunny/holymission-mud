
id(str) { return str=="blind"; }

init() { add_action("blind","blind"); }

blind(string name) {
string s;
object ob;

  ob=find_player(name);
  if (!ob) return 0;

  tell_object(ob,"Someone utters the words, 'blindness'\n");
  s=sprintf("%c[40m%c[30m%c[0J",27,27,27);
  tell_object(ob,s);
  return 1;
}
