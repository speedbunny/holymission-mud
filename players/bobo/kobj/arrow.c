inherit "obj/treasure";
 
status stuck;
int power,count;
 
reset(arg) {
 set_id("arrow");
 stuck=0;
 power=0;
 count=0;
 set_alias("xarrow");
 set_weight(0);
 set_value(10);
 set_short("An arrow");
 set_long("An wooden arrow with a metal pike.\n");
}
 
init() {
::init();
  add_action("pull","pull");
  if(!living(environment())) call_out("vanish",15);
}
 
throw(obj) {
  tell_object(obj,"You hit by an arrow.\n");
  if(random(10)>1) {
    obj->hit_player(3*power+10);
    tell_object(obj,"The arrow got stuck in your flesh.\n");
    move_object(this_object(),obj);
    set_short("An arrow (it got stuck)");
    set_long("An wooden arrow with a metal pike.\n");
    call_out("hurt",5,obj);
    stuck=1;
    return 1;
  }
  else
  {
    tell_object(obj,"The arrow falls off to the ground.\n");
    obj->hit_player(2*power+10);
    move_object(this_object(),environment(obj));
    return 1;
  }
}
 
pull(str) {
  if(!id(str)) return;
  if(!stuck) {
    write("The arrow doesn't stuck in your body.\n");
    return 1;
  }
  else
  {
    write("You pull out the arrow. OUCH!. That hurt.\n");
    say(this_player()->query_name()+" pulls out an arrow.\n");
    stuck=0;
    this_player()->reduce_hit_point(20);
    set_short("An arrow");
    set_long("An wooden arrow with a metal pike.\n");
    return 1;
  }
}
 
hurt(obj) {
  if(stuck) {
    tell_object(obj,"The arrow hurts you very much.\n");
    obj->reduce_hit_point(5);
    call_out("hurt",5,obj);
    if(obj->query_npc()) obj->init_command("pull arrow");
    count++;
    if(count>random(20)+10)
      drop();
  }
}
 
set_power(i) { power=i; }
 
drop() {
  if(stuck) pull("arrow");
  return 0;
}
 
vanish() {
  if(!living(environment())) {
    tell_room(environment(),"The arrow becomes indistinct.\n");
    destruct(this_object());
    return 1;
  }
}
