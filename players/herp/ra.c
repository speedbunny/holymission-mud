id(str) { return str=="ra"; }
short() { return "ra"; }
init() { add_action("ra","ra"); }
ra() {
object *u;
int i;

  u=users();
  for (i=0;i<sizeof(u);i++) {
    if (!u[i]->query_immortal()) remove_interactive(u[i]);
  }
  return 1;
  write("Ok.\n");
}
