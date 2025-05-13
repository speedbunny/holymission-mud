inherit "obj/armour";

string colour,read_msg;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("rose");
    set_alias("paper");
    set_short("A red rose");
    colour="red";
    set_value(50);
    set_weight(1);
    set_size(0);     
    set_ac(0);
    set_type("helmet");
    set_long("This is a beautiful rose.\n"
           + "There's a small paper attached to the rose.\n");
    set_read("Instructions:\n"
           + "ROSECOLOUR <colour> To change the rose' colour\n"
           + "ROSESEND <person> To send the rose to a person\n"
           + "ROSEWRITE <text> To write something on this paper\n");
  }
}

set_read(s) {
  read_msg=s;
}

long(str) {
  if(str=="paper") {
    write("There's something written upon it!\n");
    return 1;
  }
  ::long(str);
  write("The rose is "+colour+".\n");
  return 1;
}  

read(str) {
  if(!str) {
    notify_fail("Use read paper to read the paper!\n");
    return 0;
  }
  if(str!="paper") {
    notify_fail("Use read paper to read the paper!\n");
    return 0;
  }
  write(read_msg);
  say(this_player()->query_name()+" reads a paper.\n");
  return 1;
}

init() {
  ::init();
  add_action("rosecolour","rosecolour");
  add_action("rosewrite","rosewrite");
  add_action("rosesend","rosesend");
  add_action("smell","smell");
  add_action("read","read");
}

smell(str) {
  if(!str) {
    notify_fail("Use smell rose to smell the rose!\n");
    return 0;
  }
  if(str!="rose") {
    notify_fail("Use smell rose to smell the rose!\n");
    return 0;
  }
  if(worn) {
    notify_fail("You can't smell it while wearing it!\n");
    return 0;
  }
  write("The rose smells delicious. You really like it.\n");
  say(this_player()->query_name()+" smells a rose.\n");
  return 1;
}

rosecolour(str) {
  if(!str) {
    notify_fail("You must enter a colour for the rose!\n");
    return 0;
  }
  colour=str;
  write("Ok.\n");
  say(this_player()->query_name()+" changes the colour of a rose.\n");
  return 1;
}

rosewrite(str) {
  if(!str) {
    notify_fail("At least write SOMETHING on the paper, ok?\n");
    return 0;
  }
  read_msg=read_msg+str+"\n";
  write("Ok.\n");
  say(this_player()->query_name()+" writes something down.\n");
  return 1;
}

rosesend(str) {
object who;

  if(!str) {
    notify_fail("You must send it to someone!\n");
    return 0;
  }
  str=lower_case(str);
  who=find_living(str);
  if(!who) {
    notify_fail("That person isn't here!\n");
    return 0;
  }
  if(who==this_player()) {
    notify_fail("You can't send it to yourself!\n");
    return 0;
  }
  if(worn) {
    notify_fail("You can't send it while you're wearing it!\n");
    return 0;
  }
  if(transfer(this_object(),who)) {
    notify_fail("That person can't carry the rose!\n");
    return 0;
  }
  tell_object(who,
    this_player()->query_name()+" sends you a rose!\n");
  write("You send a rose to "+who->query_name()+". How nice!\n");
  return 1;
}
  
short() {
  return "A "+colour+" rose";
}


