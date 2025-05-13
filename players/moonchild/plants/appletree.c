int no,age;
string type;

id(str) { return str=="tree" || str=="appletree" || str=="apple tree"; }

short() {
  if(age<2) return 0;
  if(age<4) return "A small apple tree with no apples on it";
  if(age<6) return "A moderate-sized apple tree with no apples on it";
  if(age<7 || !no) return "A large apple tree with no apples on it";
  if(age==7) return "A large apple tree with " + no + " white flowers on it";
  return "A large apple tree with " + no + " ripe apples on it";
}

long() {
  if(age<2) return 0;
  return write(short() + ".\n");
}

init() { add_action("pick", "pick"); }

set_no(arg) { no=arg; }

set_type(str) { type=str; }

pick(str) {
  object apple;
  if(str=="flower" && age==7) return write("But why would you want to do that?\n");
  if(str!="apple") return;
  if(!no || age<8) return;
  apple=clone_object("obj/food");
  apple->set_name("apple");
  apple->set_short("A delicious red apple");
  apple->set_long("It looks very big and tasty.\n");
  apple->set_value(2);
  apple->set_weight(1);
  apple->set_eater_mess("You eat the apple. Delicious!\n");
  apple->set_eating_mess(" eats an apple.\n");
  apple->set_strength(5);
  if(transfer(apple,this_player())) {
    destruct(apple);
    return write("You are carrying too much!\n");
  }
  no--;
  say(this_player()->query_name() + " picks an apple.\n");
  return write("You pick an apple.\n");
}

start_growing() { age=0; grow(); }

grow() {
  age++;
  if(age<3) if(!set_light(0)) {
    destruct(this_object());
    return;
  }
  if(age>22) return die();
  else if(!set_light(0)) return die();
  if(age==2) tell_room(environment(this_object()),"Suddenly a small apple tree grows out of the ground.\n");
  else if(age>1 && age<7) tell_room(environment(this_object()),"The apple tree continues to grow.\n");
  else if(age==7) tell_room(environment(this_object()),"The apple tree bursts into flower!\n");
  else if(age==8) tell_room(environment(this_object()),"Apples start to form on the tree.\n");
  return call_out("grow",120,0);
}

die() {
  tell_room(environment(this_object()),"Suddenly the apple tree magically withers and dies.\n");
  destruct(this_object());
}
