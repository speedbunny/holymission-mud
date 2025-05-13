
  inherit "obj/monster";
       object drake;
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("armonophis");
    set_alt_name("dragon");
    set_alias("holy dragon");
    set_level(40);
    set_size(4);
    set_weight(500);
    set_gender(1);
    set_hp(5000);
    set_al(-500); 
    set_race("dragon"); 
    set_short("Armonophis, the Holy Dragon");
    set_long("You see a mighty 120 foot high dragon.\n"+
             "He looks as if he is watching something.\n"+
             "Hopefully he isn't watching you!\n");
    set_ac(10);
    load_a_chat(20,({
      "Armonophits his you with his claw !\n",
      "Armonophis thrusts at you with his tail !\n",
      "Armonophis flames you to ashes ! \n"}));
    move_object(clone_object("players/whisky/island/obj/h_skin"),
    this_object());
    move_object(clone_object("players/whisky/island/obj/holy_sword"),
    this_object());
    move_object(clone_object("/players/whisky/obj/leggings"),this_object());
    drake=this_object();    /* just to be sure */
}
}

#define CHANCE  8 	
#define DAM     80 	
#define MSG    "Suddenly "+drake->query_name()+" throws a bright ball of fire at you !\n" 

attack() {
object vic;
int i;

  if(::attack()) {			/* nur wenn er jemanden atterkiert */
    if(random(100)<CHANCE) {
      vic=all_inventory(environment(drake));
      for(i=0;i<sizeof(vic);i++) {
        if(living(vic[i]) && (vic[i]!=drake)) {
          vic[i]->hit_player(DAM+random(60));  /* just to be nice */
          tell_room(environment(drake),MSG);
        }
      }
    }
  return 1;
  }
return 0;
}
/*
init() {
   if (this_player()->query_level()>=18) {
      tell_object(this_player(),"Armonophis carefully watches his olive-tree.\n");
      attack_object(this_player());
   }
  ::init();
  }
  */

