#define RINGTEST "players/moonchild/wedding/replace_it"
#define tr(str)\
  tell_room(environment(this_object()),"The blind captain says: " + str + "\n")

inherit "obj/monster";

string first,second,genders,function,type,match,married_by;
object first_player, second_player;
int marrying, money_needed;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("captain");
  set_alias("blind captain");
  set_short("Blind captain");
  set_long(
    "This is the captain of the good ship Sparticus.  He looks rather\n"+
    "rugged and unkept. He has a large burn over his eyes which as the\n"+
    "result of a great explosion and it has left him quite blind. He is\n"+
    "still the captain of his vessel and still able to preform weddings\n"+
    "for those that aren't unwilling to pay his hefty wages.\n"+
    "Type \"weddinghelp\" for further details and instructions.\n");
  set_level(20);
  set_wc(50);
  set_race("man");
  set_hp(10000);
  money_needed=10000;
  genders=({ "creature", "husband", "wife" });
  setup_arrays();
  set_match(this_object(),function,type,match);
}

init(){
  ::init();
  add_action("weddinghelp", "weddinghelp");
  add_action("weddinglist", "weddinglist");
  add_action("marry", "marry");
}

int weddinghelp(){
  cat("/players/airborne/wedding.txt");
  return 1;
}

int weddinglist(){
  this_player()->more("/players/moonchild/wedding/WEDDINGS");
  return 1;
}

int marry(string str){
  if(money_needed>0){
    notify_fail("The captain demands his " + money_needed + " coins first.\n");
    return 0;
  }
  if(marrying){
    notify_fail("The captain is already marrying " + capitalize(first) + 
      " and " + capitalize(second) + ".\n");
    return 0;
  }
  if(sscanf(str,"%s and %s", first, second) != 2){
    notify_fail("Marry who?\n");
    return 0;
  }
  first_player=present(first,environment(this_object()));
  if(!first_player){
    notify_fail("Even the blind captain can tell that " + capitalize(first) + 
      " isn't here!\n");
    return 0;
  }
  if(!living(first_player)) {
    notify_fail("The captain only marries living people.\n");
    return 0;
  }
  if(first_player->query_npc()){
    notify_fail("The blind captain doesn't feel right about " +
      capitalize(first) + " getting married.\n");
    return 0;
  }
  if(RINGTEST->get_spouse(capitalize(first))) {
    notify_fail("But " + capitalize(first) + " is already married.\n");
    return 0;
  }
  second_player=present(second,environment(this_object()));
  if(!second_player) {
    notify_fail("Even the blind captain can tell that " + capitalize(second) + 
      " isn't here!\n");
    return 1;
  }
  if(!living(second_player)) {
    notify_fail("The captain only marries living people.\n");
    return 0;
  }
  if(second_player->query_npc()) {
    notify_fail("The blind captain doesn't feel right about " +
      capitalize(first) + " getting married.\n");
    return 0;
  }
  if(RINGTEST->get_spouse(capitalize(second))) {
    write("But " + capitalize(second) + " is already married.\n");
    return 0;
  }
  marrying=1;
  married_by=capitalize(this_player()->query_real_name());
  tr("All of you aboard my ship have been gathered");
  call_out("crap1",2,0);
  return 1;
}

crap1(){
  tr("to celebrate the marriage of these two");
  call_out("crap2",2,0);
}

crap2(){
  tr("love-locked individuals in lasting matrimony.");
  call_out("crap3",2,0);
}

crap3(){
  tr("As far as I can see, there is no reason");
  call_out("crap4",2,0);
}

crap4(){
  tr("not to marry this couple. If there is");
  call_out("crap5",2,0);
}

crap5() {
  tr("anyone who knows any just cause or impediment");
  call_out("crap6",2,0);
}

crap6() {
  tr("as to why these two people should not be");
  call_out("crap7",2,0);
}

crap7() {
  tr("joined in holy matrimony let him speak now");
  call_out("crap8",2,0);
}

crap8() {
  tr("or forever hold his peace.");
  marrying=2;
  call_out("crap9",10,0);
}

crap9(){
  if(marrying==-1) {
    tr("When you can get your guests to be ");
    tr("a little more conciderate, then I might");
    tr("concider marrying you then. But for");
    tr("now, you'll have to wait.");
    return marrying=0;
  }
  tr("Do you, " + capitalize(first) + ", take this " + capitalize(second));
  tr("to be your lawful wedded mud-" + genders[second->query_gender()] + ".");
  tell_object(first_player,"The captain tells you: A simple yes or no will "+
     "suffice.\n");
  marrying=3;
  call_out("crap10",1,0);
}

crap10(){
  if(marrying==3) call_out("crap10",1,0);
  if(marrying==-1) {
    tr("Well then... what are you wasting my time for?");
    return marrying=0;
  }
  if(marrying==4) crap11();
}

crap11(){
  tr("Do you, " + capitalize(second) + ", take this " + capitalize(first));
  tr("to be your lawful wedded mud-" + genders[first_player->query_gender()] + ".");
  tell_object(second_player,"The captain tells you: A simple yes or no will "+
     "suffice.\n");
  call_out("crap12",1,0);
}

crap12(){
  if(marrying==4) call_out("crap12",1,0);
  if(marrying==-1) {
    tr("Well then... what are you wasting my time for?");
    return marrying=0;
  }
  if(marrying==5) crap13();
}

crap13(){
  object husband,ring;
  if(first_player->query_gender()==2) husband=second;
  else if(!first_player->query_gender()) husband=second;
  else husband=first;
  tr("Very well, " + capitalize(husband) + ", you may kiss the bride.");
  money_needed=10000;
  write_file("/players/moonchild/wedding/WEDDINGS",
	ctime(time()) + ": " + capitalize(first) + " & " +
	capitalize(second) + ": Married by " + married_by + ".\n");
  say("The captain gives ring to " + capitalize(first) + ".\n",first_player);
  tell_object(first_player,"The captain gives your ring to you.\n");
  move_object(ring=clone_object("players/moonchild/wedding/ring"),first_player);
  ring->name1(capitalize(second));
  ring->name2(capitalize(first));
  ring->title_set();
  say("The captain gives a ring to " + capitalize(second) + ".\n",
    second_player);
  tell_object(second_player,"The captain gives your ring to you.\n");
  move_object(ring=clone_object("players/moonchild/wedding/ring"),
    second_player);
  ring->name1(capitalize(first));
  ring->name2(capitalize(second));
  ring->title_set();
  marrying=0;
}
  
handle_say(str) {
  string who,what;
  if(sscanf(str,"%s says: %s\n",who,what)!=2 &&
	sscanf(str,"%s tells you: %s\n",who,what)!=2) return;
  if(who=="Captain") return;
  if(marrying==2) return marrying=-1;
  what="." + lower_case(what) + ".";
  if(sscanf(what,"%sno%s",str) && (marrying==3 || marrying==4)) return marrying=-1;
  if(sscanf(what,"%syes%s",str) && (marrying==3 || marrying==4)) return marrying++;
}

setup_arrays(){
  function=({ "handle_say", 0 });
  type=({ "says", "tells you:" });
  match=({ "", " " });
}

add_money(m) {
  if(this_player()->query_immortal()) {
    write("The captain tells you: I do not accept wizards' money!\n");
    return 1;
  }
  money_needed-=m;
  if(money_needed>0) write("The captain tells you: I do nothing until I am "+
    " paid my " + money_needed + " coins.\n");
  else 
    write("The captain tells you: The wedding may now go ahead.\n");
}
