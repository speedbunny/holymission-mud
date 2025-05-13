
  inherit "obj/monster";
       object drake;
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("minorva");
    set_alt_name("dragon");
    set_alias("shy dragon");
    set_level(30);
    set_size(4);
    set_weight(80);
    set_gender(2);
    set_hp(1500);
    set_al(-500); 
    set_whimpy(100); /* giggle */
    set_race("dragon"); 
    set_short("Minorva, the shy dragon");
    set_long("You see a 80 feets high dragon.\n"+
             "She is looking a bit frightend in your\n"+
             "direction. But she seems to be very strong !\n");
    set_wc(30);
    set_ac(10);
    load_a_chat(20,({
      "Minorva hits you with his claw !\n",
      "Minorva thrusts you with his tail !\n",
      "Minorva tries to throw a fireball at you, but fails ! \n"}));
    move_object(clone_object("players/whisky/island/obj/dragontail"),
    this_object());
    drake=this_object();    /* just to be sure */
}
}

#define CHANCE  8 	
#define DAM     80	
#define MSG    "Suddenly "+drake->query_name()+" throws a bright spark of fire at you !\n" 

attack() {
object vic;
int i;

  if(::attack()) {			/* nur wenn er jemanden atterkiert */
    if(random(100)<CHANCE) {
      vic=all_inventory(environment(drake));
      for(i=0;i<sizeof(vic);i++) {
        if(living(vic[i]) && (vic[i]!=drake)) {
          vic[i]->hit_player(random(DAM)+30);
          tell_room(environment(drake),MSG);
        }
      }
    }
  return 1;
  }
return 0;
}

