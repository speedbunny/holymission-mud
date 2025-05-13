inherit "/room/room";

#define SUPERWIZ ({"tatsuo","haplo","blade"})

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Coding Room";
  long_desc =
       ("This is a room with soundproof walls.  You notice that it is\n" +
	"strangely silent within this room.\n");

dest_dir=({"/players/blade/workroom.c","out"});
property =({"has_fire"});
}

void init() {
  ::init();

    add_action("hshad","hshad");

  if(interactive(this_player())) {
    add_action("rshad", "rshad");
    (clone_object("/players/blade/wiz/listenshad"))->start_shad(this_player());
  }
  if(interactive(this_player()) && 
                member_array(this_player()->query_real_name(), SUPERWIZ)==-1){

    tell_object(this_player(), "You are not permitted into the coding room, please use mail. DO NOT TRANS.\n");
    call_out("not_allowed",1,this_player());
}
}

int hshad(){
(clone_object("/players/blade/test/ds.c"))->start_shad(this_player());
write("Shadow cloned");
return 1;
}
  
void not_allowed(object boot){
  if(boot){
    if(boot->query_level()>29)
    tell_object(boot,"The guardian sends you away\n");
    boot->move_player("X#room/church");
  }
}

int rshad() {
  object shad;
  shad = shadow(this_player(), 0);
  if(shad) {
    destruct(shad);
    write("Shadow dested.\n");
    return 1;
  }
  write("No shadow detected.\n");
  return 1;
}

void exit(object obj) {
  object shad;
  if(obj && interactive(obj)) {
    shad = shadow(obj, 0);
    if(shad) destruct(shad);
    tell_object(obj, "DEBUG: Shadow dested.\n");
  }
}


