id(str) { return str=="scan" || str=="util" || str=="scan util"; }
get() { return 1; }
short() { return "scan util"; }
long() { write(short()+".\nShows some internals of the world.\n" +
		       "Only gods will think it useful.\n" +
		       "Use with 'scan'\n"); }

init() {
  add_action("scan","scan");
  add_action("scanplayers","scanplayers");
}

scan(str) {
  int i, start, stop;
  int index;
  string xxx;
  object ob;

  if (sscanf(str,"%d %d",start,stop) != 2) return 0;
  for(i=start; i<stop; i++) {
    xxx = "obj/monster#"+i;
    if (ob = find_object(xxx)) {
      write(xxx+"\n");
      index++;
    }
  }
  write(index+"\n");
  return 1;
}

scanplayers(str) {
  int i;
  object *u;
  object ob;

if (!str) {
  u=users();
  for(i=0; i<sizeof(u); i++) {
    write(u[i]->query_real_name()+" has "+sizeof(deep_inventory(u[i]))+" objects\n");
  }
return 1;
} else {
  ob=find_player(str);
  if (!ob) return 0;
  u=deep_inventory(ob);
  for(i=0; i<sizeof(u); i++) {
    if (i<9) write(" ");
    write(i+") ");
    write(file_name(u[i])+"\n");
  }
  return 1;
}
}
