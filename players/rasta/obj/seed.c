inherit "obj/treasure";

reset(arg) {
  if(arg) return;
   set_short("some ganja seed");
  set_long("Some seed used to cultivate sensimila ganja.\n");
    set_id("ganja seed");
    set_value(20);
  set_alias("seed");
    set_weight(0);
}
  
id(str) { return str=="seed" || str=="seeds" || str=="ganja" || str=="ganja seed"; }

init() {
 ::init();
 add_action("eat","eat");
 add_action("grow","grow");
 }

eat(str) {
  if (id(str)) {
     write("You eat the ganja seed and you feel irie.\n");
     say(this_player()->query_name()+" eats ganja seed.\n");
     this_player()->heal_self(2);
     destruct(this_object());
     return 1; 
  }
}

grow(str) {
  if (id(str)) {
     write("You are waiting for the ganja to grow but nothing happens.\n");
     say(this_player()->query_name()+" is waiting for the ganja to grow.\n");
     return 1;
  }
}


