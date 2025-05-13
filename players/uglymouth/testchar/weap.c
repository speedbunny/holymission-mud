/* a typical viking weapon */
inherit "obj/weapon";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("vikingsword");
      set_alias("sword");
      set_short("A vikings sword");
      set_long("A short but very sharp sword, it's hilt in red and white. \n");
      set_class(10);
      set_value(200);
      set_hit_func( this_object() );

      }
   }

int weapon_hit() {
  write( "### weapon_hit() called.\n" );
  return 1;
}

string* query_hit_msg( int dmg, string att, object player, object target ) {
  return ({ "hit " + target->short() + " in a Viking way: crude but effective.",
    "hits you in a Viking way.",
    "hits " + (string)target->short() + " in a Viking style way." });
}
