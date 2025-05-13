inherit "/obj/treasure";
#define TP this_player()
#define PN TP->query_name()
#define QPS TP->query_possessive()

int account; 

reset(arg){

if (arg) return;

 account=3;   /* useable 3 times */ 
 set_name("limetree wand");
 set_alias("wand");
 set_short("A limetree wand");
 set_long("A limetree wand with inscription 'cold ray' on it.\n");
 set_value(4000);
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
 write("Cold ray smashes all monsters around you to the ground.\n");
 say(PN+" points "+QPS+" limetree wand to the sky.\n");
 say("Cold ray from the sky smashes you to the ground.\n");

 inv = all_inventory( environment(TP) );
 for(i=0;i<sizeof( inv );i++){
  if ( living(inv[i]) && inv[i] != TP){
     write(inv[i]->query_name()+" falls to the ground.\n");
     inv[i]->hit_player(30+random(20)+random(20),5);
   }
  }
 account--;
 if (account==0){
  write("Your wand crumbles to the dust.\n");
  destruct(this_object());
 }
 return 1;
}

