inherit "obj/weapon";
int flag;
string dummy1;
string dummy2;

void reset(int arg) {
    if(arg) return;
    flag =0;
    set_name("wand");
    set_alias("wand");
    set_short("A bone wand");
    set_long(
"This is the femur of a human being.  Someone has taken the time to meticulously "+
"runes and beautiful designs into the shaft of the bone.  The hip joint "+
"has been replaced by a massive diamond.  Leather fringe has been added "+
"to the base of the femur.\n");
    set_class(4);
    set_weight(1);
    set_value(55);
    }
init(){
  ::init();
add_action("wave","wave");
  }
wave(str){
object dude;
if(sscanf(str, "wand at %s", dummy1) != 1) {
if (flag!=4){
say(capitalize(this_player()->query_name())+" waves the bone wand.\n");
write("You wave the bone wand and you feel magic course through it.\n");
      dude = find_player(lower_case(dummy2));
      if(dude){
      hit_player(dude, random(30));
    }
      return str;

flag=flag+1;
return 1;
}
}
else {
write("You wave the bone wand and look like a fool.... nothing happens.\n");
say(capitalize(this_player()->query_name())+" shows off a bone wand.\n");
call_out("recharge",600);
return 1;
}
}
recharge(){
remove_call_out("recharge");
flag=0;
return flag;
}


