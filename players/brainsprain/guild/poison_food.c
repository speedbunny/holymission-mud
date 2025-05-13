inherit "obj/treasure";

string type;

void reset(int arg) {
  if(arg) return;
  set_name("beer");
  set_short("beer");
  set_long("beer");
  set_weight(1);
  set_id("beer");
}

string query_type(string arg){
  if(arg){
    type=arg;
  }
  return type;
}    

void init(){
  ::init();
  if(this_object()->query_type()=="drink"){
    add_action("_drink","drink");
    add_action("_drink","quaff");
  }
}

int _drink(string str) {
  write(this_object()->id()+" --- \n"+str);
  if (!str || str != this_object()->id() ) return (0);
  write("You drink the "+this_object()->query_id()+".\n");
  this_player()->add_poison(this_object()->query_strength());
  say(this_player()->query_name() + " drinks a " +
      this_object()->query_id()+".\n");
  destruct(this_object());
  return 1;
}
