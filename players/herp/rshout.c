

id(str) { return str=="rshout"; }

init() { add_action("rshout","rshout"); }

rainbow(string what) {
int i,col;
string s;

	for (col=41,i=0;i<strlen(what);i++) {
		s=sprintf("%c[%dm%c",27,col,what[i]);
		shout(s);
		col++;
		if (col==47) col=41;
	}
}

rshout(string name) {
string s;
object ob;

  shout("Herp shouts: the pot of gold is on the other side of the ");
  rainbow("rainbow");
  shout("\n");
  return 1;
}
