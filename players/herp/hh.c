id(str) { return str=="hh"; }

init() { add_action("hh","hh"); }

hh() {
string s;

  s=sprintf("%c[2J%c[1;20r",27,27);
  s=sprintf("%s%c[21;24r",s,27);
  s=sprintf("%s%c[21;1H",s,27);
  s=sprintf("%s===========================================================================\n",s);
  s=sprintf("%sYou have many gold coins, lot of exp and you are feeling good.\n",s);
  s=sprintf("%s%c[1;20r",s,27);
  /*printf(s);*/
  shout(s,this_player());
  return 1;
}
