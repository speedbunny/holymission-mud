inherit "/obj/thing";

reset(arg) {
  int i;
  string s;
  if (arg) return 1;
  set_name("fire");
  set_short("A fire");
  set_light(1);
  set_can_get(0);
  if (sscanf(file_name(this_object()),"%s#%d",s,i)==2) 
    call_out("des_fire",60);
}

id (str) { return ::id(str) || (str == "lighted_torch");}

des_fire() {
  object con,room;
  
  if (room = environment(con= environment(this_object()))) 
    tell_room(room,
      "The fire in the "+con->query_name()+" gones out.\n");
  else 
    tell_room(con, "The fire gones out.\n");

  destruct(this_object());
}
