object list;

init() {
 add_action("mass_heal"); add_verb("mass");
}

id(str) { return str == "mass_heal"; }

mass_heal() {
 int i;
 object ob;
 list = users();
 i = 0;
 ob = environment(this_player());
 while(i < sizeof(list)) {
if(environment(list[i])) {
   move_object(this_player(),environment(list[i]));
   say(this_player()->query_name()+" arrives!\n");
   tell_object(list[i],this_player()->query_name()+" heals you!\n");
   list[i]->heal_self(5000);
   say(this_player()->query_name()+" leaves!\n");
 }
   i++;
  }
 move_object(this_player(), ob);
 write("Done\n");
 return 1;
}

query_name() { return "mass_heal"; }

get() { return 1; }
