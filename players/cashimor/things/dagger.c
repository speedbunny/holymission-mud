inherit "obj/weapon";

string message,target,sender;

reset(arg) {
object who;

  ::reset(arg);
  if(!arg) {
    set_name("dagger");
    set_weight(1);
    set_short("a beautiful dagger");
    set_long("The hilt of this dagger has been exquisitely carved to\n"+
            "resemble a snake. In the mouth of the snake is a beautiful\n"
            + "@@gem_kind@@ gem. The blade has a rune-like inscription.\n");
    set_value(350);
    set_alias("inscription");
    set_read("Belongs to the collection of Ianthe.\n");
    set_class(6);
  }
  if((target)&&(message)) {
    if(who=find_living(target)) {
      tell_object(who,"There is a message for you from "+sender+".\n"
                + "It reads:\n"+message
                + "                    * * *\n");
      message=0;
    }
  }
}

gem_kind() {
  if(message) return "pulsing green";
  if(wielded) return "light green";
  return "green";
}

init() {
  ::init();
  add_action("store_it","store");
}

store_it(str) {
string str1,str2;

  if(!str) {
    notify_fail("Store message for whom?\n");
    return 0;
  }
  if(sscanf(str,"%s %s",str1,str2)==2) {
    notify_fail("That's not a playername!\n");
    return 0;
  }
  if(file_size("/players/"+str+".o")<0) {
    notify_fail("That player doesn't exist!\n");
    return 0;
  }
  if(message) {
    write("The dagger is pulsing, and can't remember another message.\n");
    return 1;
  }
  target=str;
  message="";
  write("Please enter message, use '**' to end and '~q' to abort.\n");
  say(this_player()->query_name()+" sinks into deep thought.\n");
  write("] ");
  sender=this_player()->query_name();
  input_to("add_message");
  return 1;
}

add_message(str) {
  if(str=="**") {
    write("The gem of the dagger starts pulsing.\n");
    return 1;
  }
  if(str=="~q") {
    message=0;
    return 0;
  }
  message+=str+"\n";
  write("] ");
  input_to("add_message");
}

wield(str) {
int result;

  result=::wield(str);
  if(result) call_out("notify_it",30);
  return result;
}

notify_it() {
  if(!present(this_object(),this_player())) return;
  if(!wielded) return;
  write("You suddenly get the feeling that this dagger is more than it\n"
      + "seems. It looks like you are able to store a message in it for\n"
      + "other players, which need not be on. Usage: store <name>.\n");
}
