inherit "obj/weapon";
int flag;
string dummy1;
string dummy2;
void reset(int arg) {
    if(arg) return;
    flag =0;
    set_name("rat tail");
    set_alias("tail");
    set_short("A rat tail");
    set_long(
"A rat tail, the goblin mystic's fetish.  A piece of string has been put "+
"through a hole in the tail.  The bloody stump of the tail has been nailed "+
"to a short, wooden handle.  The handle is smooth and dark from sweat.\n");
    set_class(4);
    set_weight(1);
    set_value(55);
    }
init(){
  ::init();
add_action("twitch","twitch");
  }
twitch(str){
object dude;
if(sscanf(str,"tail at %s",dummy1)==1){
if(flag<=4){
say(capitalize(this_player()->query_name())+" waves the rat's tail.\n");
write("You wave the rat tail and you feel magic course through it.\n");
dude=present(dummy1,environment(this_player()));
      if(dude){
dude->hit_player(random(30));
    }

flag=flag+1;
return 1;
}
}
else {
write("You wave the rat tail and look like a fool.... nothing happens.\n");
say(capitalize(this_player()->query_name())+" waves a rotting rat's tail.\n");
call_out("recharge",600);
return 1;
}
}
recharge(){
remove_call_out("recharge");
flag=0;
return flag;
}

