object sh;
id(str) { return str=="xe"; }
short() { return "xe"; }
init() { add_action("xe","xe"); }
get() { return 1; }
xe(arg) {


  if (!arg) {
     sh=clone_object("players/herp/guild/dodge_shadow");
     sh->start_shadow(this_player());
     return 1;
  }
  write("Shadow: "+file_name(sh)+"\n");
  return 1;
}
