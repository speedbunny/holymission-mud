#define SAFE        0
#define ARMED       1
#define EXPLODING   2
#define DELAY       3
 
string short_desc, long_desc, name, a_alias, dir1;
int state,delay;
int value,local_weight,damage;
object env1;
object me;
status fishy; 
 
reset(arg) {
  if(arg) return;
  delay=DELAY;
}
 
id(str) {
  return str == name || str == short_desc || str == "bomb" || 
          str == a_alias;
}
 
short() {
     if(!short_desc) return 0;
     return short_desc;
}
 
long() {
     write(long_desc);
     write("All bombs must be armed in order to work. 'arm <bomb>'.\n");
     write("Then 'throw <bomb> <dir>'.\n");
}
 
query_value() {
    if(state != SAFE) return 0;
    return value;
}
 
set_long(l){ long_desc = l; }
set_value(v){ value = v; }
set_weight(w){ local_weight = w; }
set_damage(d){ damage = d; }
set_id(n) { name = n;}
set_name(n) { name = n; short_desc = n; }
set_short(n) { short_desc = n; }
set_alias(a) { a_alias = a; }
 
get(){ 
     disable_commands();
     this_player()->add_weight(local_weight);
     return 1;
}
 
query_weight(){
  return local_weight;
}
 
init(){ 
          add_action("throw","throw"); 
          add_action("arm","arm");
}
 
static arm(str) {
    if(!id(str)) return 0;
    if(state != SAFE) { write(
        "The bomb is already armed.\n");
        return 1;
    }
    write("You arm the "+name+".\n");
    say(call_other(this_player(),"query_name") +
        " arms the "+name+".\n",this_player());
    state = ARMED;
    set_heart_beat(1);
    return 1;
}
 
static throw(str){
  string ob,dir;
	if(!str) return 0;
  if(sscanf(str,"%s %s",ob,dir) != 2){
    write("Type in ' throw <item> <direction> '\n");
    return 1;
    }
  if(!id(ob)) {
  write("Throw what where?\n");
  return 1;
  }
  me = this_player();
  dir1 = dir;
  move_object(this_object(),"room/void");
  drop();
  move_object(this_object(),environment(me));
  env1 = environment(this_object());
  command(dir);
    if(environment(this_object()) == env1) {
        tell_object(me,
            "The " + name + " slips from your hand!!!\n");
        say(me->query_name()+
            " accidentally drops a " + name + "!\n",
            me);
        if(state == EXPLODING) say("It's going to EXPLODE! RUUUUUUN!!!\n");
    }
  return 1;
}
 
heart_beat() {
    if(state == EXPLODING) {
        delay -= 1;
        if(delay == 0) blowup();
    }
}
 
drop() {
    if(state == ARMED) state = EXPLODING;
    this_player()->add_weight(-local_weight);
    me = this_player();
    enable_commands();
    return 0;
}
 
 
blowup(){
  object ob, env, tab;
  int i;
  env=environment(this_object());
    if(fishy) {
        state = SAFE;
        transfer(this_object(), me);
        tell_object(me,
      "That room has something wrong with it, please report this to a wiz.\n");
        fishy = 0;
       return;
    }
    if(env != env1) {
     if(name == "lady finger") {
     tell_room(env1,"You faintly hear the lady finger explode in the "+
     dir1+".\n");
     tell_room(env,"The lady finger goes POP!\n");
     destruct(this_object());
     }
     if(short_desc == "Three sticks of TNT") {
    tell_room(env1,"You hear a loud BOOM! from the "+dir1+".\n");
    tell_room(env,"The three sticks of TNT that landed in the room, "+
    "explodes!\n");
    tell_room(env,"The debris from the blast causes major damage to you!\n");
     }
     if(short_desc == "A firecracker") {
    tell_room(env1,"You hear a POP! from the "+dir1+".\n");
    tell_room(env,"The firecracker that landed in the room, makes a loud "+
     "POP!\n");
    tell_room(env,"The debris from the blast causes minor damage to you!\n");
    }
     if(short_desc == "A M-80") {
    tell_room(env1,"You hear a small BOOM! from the "+dir1+".\n");
    tell_room(env,"The M-80 that landed in the room, made a minor"+
    " explosion!\n");
    tell_room(env,"The debris from the blast causes some damage to you!\n");
    }
     if(short_desc == "A stick of TNT") {
    tell_room(env1,"You hear a BOOM! from the "+dir1+".\n");
    tell_room(env,"The stick of TNT that landed in the room, explodes!\n");
    tell_room(env,"The debris from the blast causes damage to you!\n");
    }
     if(short_desc == "A thermonuclear device") {
    tell_room(env1,"You see a mushroom cloud rising in the "+dir1+".\n");
    tell_room(env1,"BBBBBBBOOOOOOOOMMMMMMMMM!!!!!\n");
    tell_room(env,"The nuke has a MASSIVE explosion! If you\n"+
           "survive, consider yourself lucky!\n");
    }
    } else {
    tell_room(env,"The "+name+" explodes!!!!!!\n");
    tell_room(env,"You are hurt!!!\n");
    }
    tab=allocate(30);
    ob=environment();
    while(living(ob) && environment(ob)) ob = environment(ob);
    ob = first_inventory(ob);
    while(ob && i<30) {
        if(living(ob)) {
            tab[i] = ob;
            i += 1;
        }
        ob = next_inventory(ob);
    }
     while(i) {
          i -= 1;
          tab[i]->hit_player(damage);
           }
     destruct(this_object());
}
 
 
move_player(dir_dest) {
    string dest;
    if (sscanf(dir_dest, "%s#%s", dir1, dest) < 2) {
        tell_object(me, "Bad destination.\n");
        return;
   }
    if(dir1 == "X") tell_room(env1,
        short_desc+" disappeared in a burst of flame.\n");
    else {
        say(me->query_name()+" chucks a "+name+" "+dir1+".\n",me);
        tell_object(me, "You throw the "+name+" "+ dir1 +".\n");
    }
    fishy = 1;
    move_object(this_object(), dest);
    fishy = 0;
    tell_room(environment(),
        "A "+name+" just landed in the room! Run for your lives!!\n");
}
