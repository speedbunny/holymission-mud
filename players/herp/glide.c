id(str) { return str=="sil" || str=="silencer"; }

short() { return "A silencer"; }
long() { write("You see a face with no eyes, no ears and no mouth.\n"); }
init() { add_action("not","not"); }
get()  { return 1; }

not() {
string who,col;
int i;
object *u;

  u=users();
  for (i=0;i<sizeof(u);i++)
    tell_object(u[i],"[37;44m");
  return 1;
}
