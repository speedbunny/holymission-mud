id(str) { return str=="xc"; }
short() { return "xc"; }
get() { return 1; }
init() { add_action("xc","xc"); }
xc() {
mixed *dest;
int i;

  dest=environment(this_player())->query_dest_dir();
  for (i=0;i<sizeof(dest);i+=2)
	printf("%-10s - %s\n",capitalize(dest[i+1]),dest[i]->short());
  return 1;
}
