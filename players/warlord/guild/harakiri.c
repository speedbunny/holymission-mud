#define T this_player()
#define TP T->query_name()
inherit "obj/weapon";

wield() { return 1; }
reset(arg) {
  ::reset();
if (arg) return;
   set_name("knife");
    set_short("A Harakiri knife");
    set_long("A little sharp knife with a picture from Niawana.\n");
    set_class(14);
    set_weight(1);
    set_value(100);
    set_alias("harakiri knife");
 }

 init() {
  ::init();
   add_action("kill","kill");
  }

kill(str) {
   int i,j;
   i = T->query_hit_point();
   j = random(i)*random(4);
if (str!="me") return;
shout(TP+" shouts: ARGGGGG and sticks the Harakiri knife deep\ninto "+TP+"'s rips.\n");
write("You stick the Harakiri knife deep into your rips.\n");
if (j > i) {
   write("It's fullfied !\n");
   T->set_guild(0);
  return 1;
}   
 write("Bad luck try again !\n");
 T->hit_player(j);
 destruct(this_object());
return 1; }
 
