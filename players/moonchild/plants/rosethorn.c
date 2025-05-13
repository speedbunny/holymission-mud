#pragma strict_types

string type;
object ob;

status is_indoors(object room);

void reset(int arg) {
  if(!arg && file_name()!="players/moonchild/plants/rosethorn")
	call_out("grow_new", 200 + random(400), 0);
}

status id(string str) {
  return str=="thorn" || str=="rose thorn" || str=="rose_thorn";
}

status drop() {
  return 1;
}

void long() {
  write("You can't actually find the thorn.\n");
}

void set_type(string str) {
  type=str;
  ob=this_player();
}

void grow_new() {
  object r;
  if(environment()!=ob || !interactive(ob)) {
    destruct(this_object());
    return;
  }
  if(present("rose", environment(ob)) || is_indoors(ob)) {
    call_out("grow_new", 60, 0);
    return;
  }
  tell_room(environment(ob), "A rose thorn falls from " + ob->query_name()
	+ "'s clothes and lands on the ground.\n");
  move_object(r=clone_object("players/moonchild/plants/rosebush"),
	environment(ob));
  r->set_type(type);
  r->set_no(3+random(5));
}

status is_indoors(object room) {
  string room_desc,junk1,junk2;
  room_desc=(string)room->short();
  if(!room_desc) return 1;
  room_desc = "." + lower_case(room_desc) + ".";
  return sscanf(room_desc, "%sroom%s", junk1, junk2) == 2
           || sscanf(room_desc, "%soffice%s", junk1, junk2) == 2
           || sscanf(room_desc, "%ssmith%s", junk1, junk2) == 2
           || sscanf(room_desc, "%schurch%s", junk1, junk2) == 2
           || sscanf(room_desc, "%spub%s", junk1, junk2) == 2
           || sscanf(room_desc, "%sbar%s", junk1, junk2) == 2
           || sscanf(room_desc, "%sshop%s", junk1, junk2) == 2
           || sscanf(room_desc, "%spost%s", junk1, junk2) == 2
           || sscanf(room_desc, "%sbank%s", junk1, junk2) == 2
           || sscanf(room_desc, "%shall%s", junk1, junk2) == 2
           || sscanf(room_desc, "%sinside%s", junk1, junk2) == 2
           || sscanf(room_desc, "%scorridor%s", junk1, junk2) == 2
           || sscanf(room_desc, "%sentrance%s", junk1, junk2) == 2
           || sscanf(room_desc, "%sguild%s", junk1, junk2) == 2
           || sscanf(room_desc, "%stunnel%s", junk1, junk2) == 2;
}
