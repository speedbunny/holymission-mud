string name1,name2;

init() { add_action("read", "read"); }

id(str) { return (str == "flowers"); }

short() { return "A beautiful bunch of flowers"; }

long() {
  write("A beautiful bunch of flowers, with carnations, roses, irises, tulips and\n"
	+ "orchids. Attached to it is a small note. Perhaps you should read it.\n");
}

get(str) { return 1; }

query_value() { return 0; }

drop() {
  if(query_verb()=="give") {
    write("Give away the flowers? Never!\n");
    return 1;
  }
  call_out("dest", 1, 0);
  return 0;
}

dest() {
  tell_room(environment(this_object()),"As the flowers hit the ground they are ruined.\n");
  destruct(this_object());
}

set_name1(str) { name1=str; return 1; }

set_name2(str) { name2=str; return 1; }

read(str) {
  if(str=="note") {
    write("To " + name1 + " with hugs and kisses from " + name2 + ".\n");
    say(capitalize(this_player()->query_name())
	+ " looks at " + this_player()->query_possessive() + " bunch"
	+ " of flowers.\n");
    return 1;
  }
  return 0;
}
