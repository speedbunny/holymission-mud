id(str) { return str=="hi"; }

init() { add_action("hi","hi"); }

hi(string name) {
string s;
object ob;

  ob=find_player(name);
  if (!ob) return 0;

  s="";
  s=sprintf("%s%c[2J",s,27);
  s=sprintf("%s%c[5;10r",s,27);
  s=sprintf("%s%c[4;1H",s,27);
  s=sprintf("%s===========================================================================\n",s);
  s=sprintf("%s%c[11;1H",s,27);
  s=sprintf("%s===========================================================================\n",s);
  s=sprintf("%s%c[5;1H",s,27);
  /*printf(s);*/
  /*shout(s,this_player());*/
  tell_object(ob,s);
  return 1;
}
