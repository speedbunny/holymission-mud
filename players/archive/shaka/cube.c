id(str) { return str=="cube"; }
short() { return "Waldo's magical cube"; }
long() {
   write("This is Waldo's magical cube. It is solid black on all six sides.\n");
   write("What does it do? How is it operated? Who knows?\n");
   }
query_value() { return 20000; }
get() {
   if (call_other(this_player(),"query_name",0)=="Zephram")
      return 1;
   else return 0; }
init() {
   add_action("summon"); add_verb("summon");
   add_action("snatch"); add_verb("snatch");
   add_action("probe"); add_verb("probe");
   }
summon(str) {
object thing;
string name;

   if (!str) {
      write ("Summon whom?\n");
      return 1; }
   else {
      thing=find_living(str);
      if(thing) {
      name=call_other(thing,"query_name",0);
      write(name+" appears.\n");
      tell_object(thing,"You are suddenly whisked off to another place.\n");
      say(call_other(this_player(),"query_name",0)+
         " speaks a few wizardly words and "+name+" appears.\n");
      transfer(thing,environment(this_player()));
      return 1;
      }
      else write(str+" not found.\n"); return 1; }
   }
snatch(str) {
object thing;
string name;
   if (!str) {
      write ("Snatch whom?\n");
      return 1; }
   else {
      thing=find_living(str);
   if(thing) {
      name=call_other(thing,"query_name",0);
      write("You now have "+name+" in your pocket.\n");
      say(call_other(this_player(),"query_name",0)+
         " just pocketed "+name+"\n");
      tell_object(thing,"You are now in "+
         call_other(this_player(),"query_name",0)+
         "'s pocket.\n");
      move_object(thing,this_player());
      return 1;
      }
      else write(str+" not found.\n"); return 1; }
   }
probe(str) {
object thing;
   if (!str) {
      write("Probe what?\n");
      return 1; }
   else {
      thing=find_living(str);
   if(thing) {
      call_other(thing,"show_stats");
      return 1;
      }
   else write(str+" not found.\n"); return 1; }
   }

