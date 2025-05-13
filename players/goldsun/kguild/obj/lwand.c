inherit "/obj/treasure";
#define TP this_player()

int account; 

reset(arg){

if (arg) return;

 account=5;   /* useable 5 times */ 
 set_name("oak wand");
 set_alias("wand");
 set_short("A oak wand");
 set_long("An oak wand with inscription 'lightning' on it.\n");
 set_value(2000);
 set_weight(1);
 }

init(){
 ::init();
 add_action("do_cast","cast");
 }

int do_it(object ob){

 if (!living(ob)){
  write("You cannot hit a thing !\n");
  return 1;
 }
 if (!ob->query_npc()){
  write("You are not allowed to hit a player by this spell !\n");
  return 1;
 }
 write("You cast a lightning at "+ob->query_name()+".\n");
 say(TP->query_name()+" casts a lightning at "+ob->query_name()+".\n");
 ob->hit_player(100,5);
 account--;
 if (account==0){
  write("Your wand crumbles to the dust.\n");
  destruct(this_object());
 }
 return 1;
}


int do_cast(string whom){
 object att;

  if (!whom){   /* we have to fight */
    if (TP->query_attack()){
      att=TP->query_attack();
      if (present(att,environment(TP))) do_it(att);
      else write(capitalize(whom)+" isn't here.\n");
    }
    else write("Cast at whom ?\n");
  }
   else{
     if (present(whom,environment(TP))){
     att=present(whom,environment(TP));
     do_it(att);
     }
     else write(capitalize(whom)+" isn't here.\n");
   }
 return 1;
 }
