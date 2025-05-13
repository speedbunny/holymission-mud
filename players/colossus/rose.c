string colour,msg,tmp;
int ct;

reset(arg) { if(!arg) colour="beautiful red"; }

id(str) { return str=="rose" || str==colour + " rose"; }

short() { return msg ? "A " + colour + " rose with a message written on it" :
		"A " + colour + " rose"; }

long() {
  write(short() + ".\n\n"
	+ "Commands: send <player>   - sends the rose to a player.\n"
	+ "          colour <colour> - changes the colour of the rose.\n"
	+ "          write message   - allows you to write a message on the rose.\n"
	+ "          erase message   - removes the message.\n"
	+ "          read message    - read the message (if any).\n");
  return;
}

query_weight() { return 0; }

query_value() { return 0; }

get() { return 1; }

drop() { return 0; }

init() {
  add_action("_send", "send");
  add_action("_colour", "colour");
  add_action("_write", "write");
  add_action("_erase", "erase");
  add_action("_read", "read");
}

_send(str) {
  object ob;
  if(!str) return;
  if(!(ob=find_player(str))) write(capitalize(str) + " is not logged in.\n");
  else if(!interactive(ob)) write(capitalize(str) + " is netdead.\n");
  else if(ob==this_player()) write("How narcissistic.\n");
  else {
    write("You send " + short() + " to " + capitalize(str) + ".\n");
    tell_object(ob, "You recieve a " + short() + " from "
	+ this_player()->query_name() + ".\n");
    move_object(this_object(),ob);
  }
  return 1;
}

_colour(str) {
  if(!str) write("Your rose's colour is " + colour + ".\n");
  else if(strlen(str)>40) write("That's too long to be a real colour.\n");
  else {
    colour=str;
    write("The rose changes its colour to " + colour + ".\n");
  }
  return 1;
}

_write(str) {
  if(str!="message") return;
  tmp="";
  ct=0;
  write("Enter your message, one line at a time. Finish with ** on its own\n"
	+ "at the beginning of a line. Maximum message length is 15 lines.\n"
	+ "To abort, enter ** on its own at the beginning of the first line.\n]");
  input_to("enter_message");
  return 1;
}

enter_message(str) {
  if(!str) str="";
  if(str=="**") {
    if(!ct) {
      write("Message aborted.\n");
    } else {
      msg=tmp;
      write("Message entered.\n");
    }
  } else {
    tmp+=str+"\n";
    if(ct++==14) return enter_message("**");
    write("]");
    input_to("enter_message");
  }
  return;
}

_erase(str) {
  if(str!="message") return;
  msg=0;
  write("Message erased.\n");
  return 1;
}

_read(str) {
  if(str!="message") return;
  if(!msg) write("There is no message on this rose.\n");
  write("The message reads:\n\n" + msg);
  return 1;
}

set_up(str) { colour=str; }
