
id(str) { return str=="rain"; }

init() { add_action("rain","rain"); }

rainbow(object ob,string what) {
int i,col;
string s;

	for (col=41,i=0;i<strlen(what);i++) {
		s=sprintf("%c[%dm%c",27,col,what[i]);
		tell_object(ob,s);
		col++;
		if (col==47) col=41;
	}
	tell_object(ob,"\n");
}

rain(string name) {
string s;
object ob;

  ob=find_player(name);
  if (!ob) return 0;

  rainbow(ob,"Someone utters the words, 'Look, a rainbow!'\n");
  return 1;
}
