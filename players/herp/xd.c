id(str) { return str=="xd"; }
short() { return "xd"; }
init() { add_action("xd","xd"); }
get() { return 1; }
xd() {
object *u;
int i,w,v;

  u=users();
  for (i=0;i<sizeof(u);i++)
    printf("%-30s %7d %7d %7d\n",u[i]->query_name(),w=u[i]->query_weight(),v=u[i]->query_str(),w*100/v);
  return 1;
}
