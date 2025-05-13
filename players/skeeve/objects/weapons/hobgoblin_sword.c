inherit "/obj/weapon";

int damage;

#define STR 0x01
#define DEX 0x02

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("old sword");
    set_alt_name("sword");
    set_alias("hobgoblin_sword");
    set_class(12);
    set_type(STR&DEX);
    set_weight(3);
    damage = 0;
    set_value(120);
    set_short("A old sword");
    set_long("This old sword is used in many fights, but his owner \n"
         +"has never conserve it. So it has many dents and swellings.\n");
    set_hit_func(this_object());
  }
}

weapon_hit(ob) { /* The special hit function */
  if(!wielded_by->query_NPC()) 
    if (!random(3)) {
      damage++;
      set_value((this_object()->query_class()-damage)*10);
      if (damage<this_object()->query_class())
        write("Iron shivers brokes from your sword, as you hits your enemy.\n");
      else {
        say(this_player()->query_name()+"'s sword brokes into 100 shivers.\n");
        write("Your sword brokes into 100 shivers, as you hit your enemy.\n");
        destruct(this_object());
      }
    }
  return -damage;
}
