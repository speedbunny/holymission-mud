/*coded by gandalf for the samurai guild*/
inherit "obj/treasure";

query_auto_load() { return "/players/haplo/ishikawa/obj/lion:";}
string colour;

reset(arg) {
  ::reset(arg);
  if(arg)
    return;
colour=random(2) ? "A Brown" : "A Strong";
  set_id(colour + " Lion");
  set_alias("lion");
  set_alt_name("hobbes");
  set_short(capitalize(query_name()));
  set_long(short() + ".\nYou could squeeze it.\n");
  set_value(25);
}

init() {
  ::init();
   add_action("soozie", "squeeze");
}

soozie(str) {
  if(!id(str))
    return;
  write("You squeeze the " + lower_case(short()) + ".\n");
  say(this_player()->query_name() + " squeezes the " + lower_case(short()) + ".\n");
tell_room(environment(this_player()), short() + " roars mightily! *ROAR*!\n");
  return 1;
}
drop(){
   if(query_verb()== "sell" || "give"){
      write("You could never get rid of your beautiful Lion!!\n");
      return 1;
       }
   write("You Lion is to strong and pretty to drop!\n");
     return 1;
    }
