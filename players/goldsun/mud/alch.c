inherit "obj/monster";

object  w,list;

reset(arg){
 ::reset(arg);
 if(!arg){
   set_level(19);
set_gender(1);
   set_hp(1800);
   set_race("dwarf");
   set_name("zoggo");
   set_alt_name("alchemist");
   set_al(500);
   set_short("Zoggo the Alchemist");
   set_long("The Alchemist is one of the wisest men in all the land!  His\n"+
                  "powers are unmatched!  His knowledge unrivaled!  His lunacy\n"+
                  "beyond comprehension!\n @@chk_boy@@\n");
   set_wc(30);
   set_ac(12);
   set_size(2);
   set_aggressive(0);
   set_whimpy(-1);
w=clone_object("/players/kawai/ptools/cloak");
transfer(w,this_object());
command("wear cloak",this_object());
   w=clone_object("obj/money");
   w->set_money(random(1000)+800);
  transfer(w,this_object());
}}
long() {
  printf("%s%s",process_string(long_desc),tell_health());}
 worry() {call_out("worry2",6,0); return 1;}
worry2() {if (!cb()) {
  say("Zoggo says: I wish I had a piece of ore to complete this experiment!\n"); return 1;}
  say("Zoggo bounces around the room in joy.\n"); return 1;}

chk_boy() {
  list=present("kq1-list",this_player());
  if(!list){
      return "He looks preoccupied.";}
  if(list->query_ore()) {
      return "He is quite happy.";}
  return "He looks preoccupied.";}



cb() {
  list=present("kq1-list",this_player());
  if(!list){
      return 0;}
  if(list->query_ore()) {
      return 1;}
  return 0;}
init() {add_action("askk","ask");}
askk(str) {
  string k,m;
   if(!str) {return 1;}
   if(sscanf(str,"%s %s",k,m)==2) {
     if(id(k)) {
      catch_tell(this_player()->query_name()+" tells you: "+m+"\n");
      return 1;}}}

catch_tell(arg) {
 object list,who,ore;
 string w, item,x;
 if(sscanf(arg,"%sore%s",w,item)==2) {
    who=this_player();
       if (!cb()) {
           if(!ore=present("kq1-ore",this_player())) {
              tell_object(who,
              "Zoggo tells you: I've been working on an experiment for the\n"+
              "King lately, but I need a piece of ore if I can finish it.  If\n"+
              "you would go back to the mine and get my one, I'm sure\n"+
              "the King would most appreciate it!\n"); return 1;}
           tell_object(who,
             "Zoggo tells you: I see you got me my ore!  Thank you "+
             "very much!\n"+
             "Zoggo takes the ore and places it in an empty vial\n"+
             "somewhere among a great contraption.  Moments\n"+
             "later, after a great deal of noise and smoke, a\n"+
             "cheeseburger appears where the ore was.\n"+
             "Zoggo tells you: PERFECT!  And it's medium rare too!\n"+
             "I'm sure the King will be most pleased!\n");
             if(!list=present("kq1-list",this_player())) {
                 transfer(list=clone_object("players/kawai/obj/chklist"),this_player());}
             list->set_ore(1); destruct(ore);
             return 1;}
       tell_object(who, "Zoggo exclaims: IT WORKS!  IT WORKS!!\n");
       return 1;}
  if(sscanf(arg,"%sking%s",x,item)==2) {
             who=this_player();
             if (!cb()) {tell_object(who,
           "Zoggo says: I'll put in a good word with you if you get me some ore!\n"); return 1;}
       tell_object(who, "Zoggo says: It works!  It WORKS!!!!!  I'll let the King\n"+
                                "know of your great service!\n");
       return 1;}
}

enter_inventory(ob) {
#define who previous_object()
   if(!ob->id("kq1-ore")) {
        tell_object(who,"Zoggo tells you: Thanks, but I don't think it will work...\n"); 
         return 1;}
   if(creator(ob)!="kawai") {
        tell_object(who,"Zoggo tells you: What!? This is no good!\n");
        destruct(ob); return 1;}
  if(!cb()) {
         tell_object(who,
             "Zoggo tells you: I see you got me my ore!  Thank you "+
             "very much!\n"+
             "Zoggo takes the ore and places it in an empty vial\n"+
             "somewhere among a great contraption.  Moments\n"+
             "later, after a great deal of noise and smoke, a\n"+
             "cheeseburger appears where the ore was.\n"+
             "Zoggo tells you: PERFECT!  And it's medium rare too!\n"+
             "I'm sure the King will be most pleased!\n");
             if(!list=present("kq1-list",this_player())) {
                 transfer(list=clone_object("players/kawai/obj/chklist"),this_player());}
             list->set_ore(1); destruct(ob);
             return 1;}
       tell_object(who, "Zoggo exclaims: IT WORKS!  IT WORKS!!\n");
#undef who
       return 1;}

