int col=41;

id(str) { return str=="raincall"; }

init() { add_action("raincall","raincall"); }

rainbow() {
string s;
object ob1,ob2;

	s=sprintf("%c[%dm",27,col);
	ob1=environment(this_object());
	ob2=environment(ob1);
	if (ob2) ob1=ob2;
	if (ob2) tell_object(ob2,s);
	tell_room(ob1,s);
	col++;
	if (col==47) col=41;
}

rainman() {

  rainbow();
  call_out("rainmain",1);
  return 1;
}

raincall() {

  rainman();
  printf("Sunlights sparkles in from the wink of your eyes ...\n");
  return 1;
}
