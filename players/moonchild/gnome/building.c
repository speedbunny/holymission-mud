inherit "room/room";

int done;
int *soln;

reset(arg) {
  int i;
  done=0;
  soln=allocate(10);
  for(i=0;i<10;i++)
    soln[i]=1+random(3);
  if(arg) return;
  set_light(1);
  short_desc="A building";
  long_desc="This building was clearly once a storeroom. Nothing is left\n"
	+ "here now, except for three levers implanted in the wall.\n";
  dest_dir=({ "players/moonchild/gnome/eroad2", "south" });
  items=({ "lever", "Which lever? Lever 1, lever 2 or lever 3",
	"levers", "Which lever? Lever 1, lever 2 or lever 3",
	"lever 1", "Just an ordinary lever",
	"lever 2", "Just an ordinary lever",
	"lever 3", "Just an ordinary lever",
	"wall", "There are three levers in it" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("pull", "pull");
  add_action("pull", "shift");
  add_action("pull", "push");
  add_action("pull", "move");
}

pull(str) {
  int no;
  if(!str) return;
  if(str=="lever" || str=="levers") {
    write(capitalize(query_verb()) + " which lever?\n");
    return 1;
  }
  if(!sscanf(str,"lever %d",no)) return;
  if(no<1 || no>3) {
    write("I don't see that lever here.\n");
    return 1;
  }
  write("You " + query_verb() + " the lever.\n");
  say(this_player()->query_name() + " " + query_verb());
  say(query_verb()=="push" ? "es a lever.\n" : "s a lever.\n");
  if(done==-1) return 1;
  if(no==soln[done]) {
    done++;
    tell_room(this_object(),"You hear a clunking sound.\n");
    if(done==10) {
      object c;
      tell_room(this_object(),"Something falls down out of the wall.\n");
      move_object(c=clone_object("players/moonchild/gnome/crystal"),this_object());
      c->set_type(0);
      done=-1;
    }
  } else {
    tell_room(this_object(),"You hear a clicking sound.\n");
    done=0;
  }
  return 1;
}
