int no,age;
string type;

id(str) { return str=="bush" || str=="rosebush" || str=="rose bush"; }

short() {
  if(age<2) return 0;
  if(age<4) return "A small rose bush";
  if(age<6) return "A moderate-sized rose bush";
  if(age<7 || !no) return "A large rose bush";
  return "A large rose bush with " + no + " " + type + " flowers on it";
}

long() { return write(short() + ".\n"); }

init() { add_action("pick", "pick"); }

set_no(arg) { no=arg; }

set_type(str) { type=str; }

pick(str) {
  object rose;
  if(str!="rose" && str!="flower") return;
  if(!no || age<7) return write("There are no roses on the bush.\n");
  rose=clone_object("players/moonchild/puzzle/rose");
  if(transfer(rose,this_player())) {
    destruct(rose);
    return write("You are carrying too much!\n");
  }
  no--;
  rose->set_up(type);
  say(this_player()->query_name() + " picks a rose.\n");
  return write("You pick a " + type + " rose.\n");
}

start_growing() { age=0; grow(); }

grow() {
  age++;
  if(age<3) if(!set_light(0)) {
    destruct(this_object());
    return;
  }
  else if(age==14 || !set_light(0)) return die();
  if(age==2) tell_room(environment(this_object()),"Suddenly a small rose bush grows out of the ground.\n");
  else if(age>1 && age<7) tell_room(environment(this_object()),"The rose bush continues to grow.\n");
  else if(age==7) tell_room(environment(this_object()),"The rose bush bursts into flower!\n");
  return call_out("grow",20,0);
}

die() {
  tell_room(environment(this_object()),"Suddenly the rose magically withers and dies.\n");
  destruct(this_object());
}
