inherit "obj/monster";

void reset(int arg) {

  ::reset(arg);
  if(arg) return;
  set_name("orc shaman");
  set_alias("shaman");
  set_race("orc");
  set_short("A huge and ancient orc shaman");
  set_long("A huge and ancient orc shaman. He seems to have learnt\n"	+
           "very many things that orcs don't usually know.\n");
  set_level(20);
  set_aggressive(1);
  set_al(-300);
  set_whimpy(-1);
  add_money(500 + random(1001));
  move_object(clone_object("players/moonchild/pot/staff"), this_object());
  if(!random(3)) {
    move_object(clone_object("players/moonchild/pot/dagger"), this_object());
    init_command("wield dagger");
  }
}

varargs mixed hit_player(int dam, int type, mixed elem) {
  object weap;
  weap = this_player()->query_wielded();
  if(!weap || !weap->id("orc slayer")) {
    tell_room(environment(this_object()),
              "Orc shaman brushes aside the attack with " +
              "a flick of his wrists.\n");
    dam=0;
  }
   return ::hit_player(dam,type,elem);
}
