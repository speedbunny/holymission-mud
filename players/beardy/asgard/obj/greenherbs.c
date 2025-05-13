inherit "obj/treasure";

reset(int arg) 
{ if(arg) return 0;

  set_id("herbs");
  set_short("Some green herbs");
  set_long("Some strange green herbs\n");
  set_value(2);
  set_weight(0);
}
init() {
 ::init();
 add_action("eat","eat");
 
 }
int eat(string str) 
{ if (str!="herbs")  return 0; 
  
  write("Baaaa they are tasting awful.\n"+
        "But you fell better now.\n");
  say(this_player()->query_name()+" eats some herbs.\n");
  if(this_player()->query_max_hp()-this_player()->query_hp()>=40)
    this_player()->reduce_hit_point(-20-random(20)); 
  destruct(this_object());
  return 1;
}
