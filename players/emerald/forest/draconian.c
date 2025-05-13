#define TR(x) tell_room(environment(), x)
#define TPN this_player()->query_name()
#define TO this_object()

inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg)return;
  switch(random (5)) {
    case 0: set_name("bozak draconian");
      set_long("The draconian is much taller than you and is covered in " +
               "rippling muscles.  It is dressed in armour and a robe.  " +
               "Beneath its scaly skin, you detect the aura of magic.\n");
      set_alias("bozak"); break;
    case 1: set_name("kapak draconian");
      set_alias("kapak"); break;
    case 2: set_name("baaz draconian");
      set_alias("baaz"); break;
    case 3: set_name("aurak draconian");
      set_alias("aurak"); break;
    case 4: set_name("sivak draconian");
      set_long("The draconian is huge and muscular. It's skin is covered " +
               "in silver scales.\n");
      set_alias("sivak"); break;
  }
  set_level(13+random(3));
  set_long("A " + name + ". ");
  set_race("draconian");
  set_aggressive(1);
  add_money(500+random(1001));
  set_dead_ob(this_object());
}

int monster_died(object ob) {
  object s;
  switch(name) {
    case "aurak draconian":
      TR("Aurak draconian explodes, severely injuring you.\n");
      this_player()->hit_player(30+random(51));
      destruct(this_object());
      return 1;
      break;
  case "kapak draconian":
    TR("Kapak draconian turns into a pool of acid.\n");
    move_object(clone_object("/players/emerald/forest/acid_pool"),
      environment());
    destruct(this_object());
    return 1;
    break;
  case "sivak draconian":
    say("The Sivak draconian turns into a exact duplicate of "+TPN +" as "+
        "it dies.\n");
    write("The Sivak draconian morphs into your form as it dies.\n");
    move_object(s=clone_object("obj/corpse"), this_object());
    s->set_id("corpse");
    s->set_alias("corpse");
    s->set_name( this_player()->query_name() );
    destruct(this_object());
    return 1;
    break;
  case "baaz draconian":
    TR(capitalize(name) + " turns into a statue made of stone.\n");
    if(!random(3)) {
      object w;
      w=(object)this_player()->query_wielded();
      if(w && !(int)w->drop(1) && w) {
        destruct(w);
        write("Your weapon vanishes!\n");
      }
    }
    move_object(clone_object("/players/emerald/forest/statue"), TO);
    destruct(this_object());
    return 1;
    break;
  case "bozak draconian":
    say("Bozak draconian explodes in "
       + (string)this_player()->query_name() + "'s face.\n");
    write("Bozak draconian explodes in your face!\n");
    this_player()->hit_player(30+random(51));
    destruct(this_object());
    return 1;
    break;
 }
 if (ob)
      destruct(ob);
  return 1;
}
