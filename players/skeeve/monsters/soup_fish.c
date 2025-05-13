inherit "/obj/monster";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("fish");
    set_alt_name("fish");
    set_alias("fish");
    set_short("A fish");
    set_long("A fish for the fishsoup.\n");
    set_race("fish");
    set_gender(random(2)+1);
   set_level(1);
    set_al(0);
    set_sp(0);
    set_wc(5+random(4));
    set_ac(1);
    set_hp(1);
    set_whimpy(25); 
    set_size(2);
    set_dead_ob(this_object());
} }

monster_died(ob) {
   object fillet;
   fillet = clone_object(OBJECTS+"fillet");
   fillet->set_short(capitalize(name) + " fillet");
   fillet->set_alias(name+" fillet");
   fillet->set_long("A raw piece of " + name + "\n");
   move_object(fillet,this_object());
   this_player()->add_exp(-10);
   return 0;
}

config (version) {
  string *str;
  int i,*ints;
  str =({"herring","perch","cod","salmon","tunny"});
  i = (stringp(version))? member_array(version,str) : version;
  if (i<0)i=random(sizeof(str));

  set_name(str[i]);
  
  str = ({"A good small herring","A very great perch","A small cod",
          "a fine red salmon","A big black tunny"});
  set_short(str[i]);
  
  str =({"The herring has a piquant taste. Every fish soup needs it!\n",
    "A perch is absolutly necessary for a fish soup!\n",
    "A cod makes each fish soup better!\n",
    "A red salmon tastes very fine. Every fish soup needs it!\n",
    "The big black tunny gives some fillet. It makes one strong and healthy!\n"});
  set_long(str[i]);
  
  ints =({3,4,2,3,3});
  set_size(ints[i]);

  set_race("fish");
  return (this_object());
}
