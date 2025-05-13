
/* mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

#define TO	this_object()
#define SAY(x); tell_room(environment(this_object()),x);
#define BACK	"players/herp/workroom"

id(str) { return "wind"; }
short() { return "Through a hole in the wall you can feel the wind blowing"; }
long() {
  write("You feel colder looking at the hole.\n" +
	"Here it is where Herp summons the West- and the Eastwind\n" +
	"and the Northwind and the Southwind ...\n");
}

init() { 
  add_action("do_exting","extinguish");
}

do_exting(str) {
object *u,ob;
int i;

  if (str!="all") return;

  u=users();
  for (i=0;i<sizeof(u);i++) {
     write("["+i+"] ");
     write(u[i]);
     write(" "+u[i]->query_real_name());
     ob=present("torch",u[i]);
     if (ob) write(" had a torch\n");
     else write(" had no torch\n");
     if (ob && ob->query_is_lit()) {
	move_object(TO,environment(u[i]));
	SAY("The "+randdir()+"wind extinguishes the torch of "+u[i]->query_name()+".\n");
	ob->ext_silent();
     }
  }
  move_object(TO,BACK);
  return 1;
}

randdir() {
  switch(random(4)) {
  case 0:return"North";
  case 1:return"South";
  case 2:return"West";
  case 3:return"East";
  }
}
