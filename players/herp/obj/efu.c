get() { return 1; }
id(str) { return str=="efu"; }
init() { add_action("efu","efu"); }
efu() {
int i;
object *u;

  u=efun::users();
  for (i=0;i<sizeof(u);i++)
    write(u[i]->query_level()+" "+u[i]->query_real_name()+"\n");
  return 1;
}
