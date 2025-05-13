inherit "obj/treasure";

string type;
int poison;

void reset(int arg) {
  if(arg) return;
  set_name("beer");
  set_short("beer");
  set_alt_name("beer");
  set_alias("beera");
  set_long("beer");
  set_weight(1);
  set_id("beer");
}

int _drink(string str) {
  write(/*this_object()->query_id()+" "+*/ str+"\n");
  if (!str || !this_object()->id(str) ) return (0);
  write("You drink the "+this_object()->short()+".\n");
  this_player()->add_poison(this_object()->query_poison());
  say(this_player()->query_name() + " drinks a " +
      this_object()->short()+".\n");
  destruct(this_object());
  return 1;
}

void init(){
  ::init();
  if(this_object()->query_food_type()=="drink"){
    add_action("_drink","drink");
    add_action("_drink","quaff");
  }
  return;
}

string query_food_type(string arg){
  if(!arg) return type;
  type=arg;
  this_object()->init();
  return type;
}    

int add_poison(int arg)   { poison=arg;    }    
int query_poison()        { return poison; }







