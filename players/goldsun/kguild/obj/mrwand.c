inherit "/obj/treasure";
#define TP this_player()
#define PN TP->query_name()
#define QPS TP->query_possessive()

int account; 

reset(arg){

if (arg) return;

 account=2;   /* useable 3 times */ 
 set_name("moontree wand");
 set_alias("wand");
 set_short("A moontree wand");
 set_long("A moontree wand with the inscription 'moon ray' on it.\n");
 set_value(5000);
 set_weight(1);
 }

init(){
 ::init();
 add_action("do_cast","cast");
 }

int do_cast(){
 int i;
 object *inv;

 write("You point your wand to the sky.\n");
 write("Shiny moonlight harms all monsters around you.\n");
 say(PN+" points "+QPS+" moontree wand to the sky.\n");
 say("Shiny moonlight harms you. You feel less powerful!\n");

 inv = all_inventory( environment(TP) );
 for(i=0;i<sizeof( inv );i++){
  if ( living(inv[i]) && inv[i] != TP){
     write(inv[i]->query_name()+" screams in agony.\n");
     inv[i]->hit_player(35+random(10)+random(10),5);
     TP->heal_self(5);
   }
  }
 account--;
 if (account==0){
  write("Your wand crumbles to dust.\n");
  destruct(this_object());
 }
 return 1;
}

