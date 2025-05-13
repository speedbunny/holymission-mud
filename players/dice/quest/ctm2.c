inherit "obj/monster";

string function,check,match;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("ctm");
    set_short(0);
    set_long("This is Dice's ctm.\n");
    set_level(100);
    set_hp(10000);
    function=({"say_it","say_it","say_it","say_it"});
    check=({"says: Evil spirit let me out.",
            "says: evil spirit let me out",
            "says: Evil spirit let me out",
            "says: evil spirit let me out."});
    match=({"","","",""});
    set_match(this_object(),function,check,match);
  }
}

say_it(str) {
string who,whoex,whostr,junk;
object whoobj;

  if(sscanf(str,"%s says: %s",who,junk)!=2) return;
  whoex=explode(who," ");
  whostr=whoex[sizeof(whoex)-1];
  whoobj=find_living(lower_case(whostr));
  if(!whoobj) return;
  whoobj->move_player("by a big boney hand#players/dice/quest/q4");
  tell_object(whoobj,"hello");
     return 1;
}
