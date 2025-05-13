inherit "room/room";

id(str) {
 return str == "carriage" || str == "coach";
}

query_value() { return 0; }

long(str) {
 if(str == "carriage" || str == "coach") {
  write("The carriage is made of sturdy oak. Even though the\n");
  write("carriage looks old, is looks strong enough to withstand\n");
  write("the strongest of storms. The carriage is ready to leave\n");
  write("when you are.\n");
  }
 return 1;
}

short() { return "A horse-drawn Carriage"; }

init() {
 add_action("enter"); add_verb("enter");
 call_other("players/ted/in_carriage", "set_find", this_object());
}

enter(str) {
 if(str == "carriage" || str == "coach") {
  say(call_other(this_player(),"query_name")+" enters the carriage.\n");
  write("You enter the carriage.\n");
  call_other(this_player(),"move_player","into the carriage#players/ted/in_carriage");
  return 1;
 }
}

get() { return 0; }
