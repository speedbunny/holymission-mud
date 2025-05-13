inherit "/obj/thing";
#define TP this_player()
reset (arg) {
if (arg) return 1;
set_name("horn");
set_short("A small horn");
set_long("A little rusty horn with some ancient writing scrawled on it");
set_value(15);
set_weight(1);
}

init() {
   ::init();
   add_action("_blow","blow");
}

int _blow(string str) {
   if(str!="horn") return 0;
   write("You blow into the horn.\n");
   say(TP->query_name()+" blows "+TP->query_possessive()+" horn.\n");
   if(environment(TP)->sound_horn()!=1) {
      write("The sound of the horn reverberates!\n");
      say("The sound of the horn reverberates!\n");
   }
   return 1;
}
