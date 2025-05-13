inherit "obj/monster";
#include "/players/sourcer/special/block.c"
 

object me;
 
  reset(arg) {
    ::reset(arg);
  if (!arg) {
    block_reset();
    set_block_chance (70);
    set_name("spider");
    set_alt_name("black spider");
    set_level(21);
    set_size(2);
    set_hp(1000);
    set_al(-100); 
    set_race("spider"); 
    set_wimpy (-1);
    set_short("A black spider");
    set_long("You see a big black spider.\n"+
             "It has a red cross on its back.\n");
    set_wc(5);
    set_ac(71);
    set_aggressive(1);
    load_chat(10,({
      "T a p   T a p  T a p\n"}));
    me=TO;    
}
}

#define CHANCE  20 	
#define MSG	me->query_name()+" bites into "+vic->query_name()+"'s leg !\n" 

attack() {
object vic;
vic=TP->query_attack();

  if(::attack()) {	
    if(random(100)<CHANCE) {
      tell_room(E(TO),MSG);
      tell_object(vic," You feel a weak sting on your feet !\n");
      vic->add_poison(vic->query_max_hp()/16-1);
        }
      }
  return 1;
  }
  init() {
   object ob;
   if (ob=present("rat",environment())) {
   attack_object(ob);
   }
   add_action("hold","hold");
   add_action("do_block","east");
   block_init();
   ::init();
  }

  hold(arg) {
   if (arg!="spider" && arg!="brown spider") return;
   tell_room(E(TO)," The spider hides under a stone !\n");
      destruct(TO); 
    return 1;
   }
   

    
int do_block() 
{
TELL("The spider doesn`t let you go there !\n");
return 1;
}

