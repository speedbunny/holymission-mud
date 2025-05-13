/* ########################################################################
                J A C K S - R I N G   (c) Whisky 
   
   please don't copy that ring such items should be unique.......
   ######################################################################## */

#define MAXHP  this_player()->query_max_hp()
#define HP     this_player()->query_hp()

inherit "obj/armour";


init() {
  ::init();
  add_action("rahanatem","rahanatem");  
  /* a magic item should only have one function Whisky */
  add_action("read","read");
}
rahanatem() {

   if (HP > (MAXHP-40)) {
      write("Your ring starts to vibrate, but nothing more happens.\n");
      }
      
   else if (this_player()->query_spell_points() < 40) { 
           write("You are too low on spellpoints.\n");
     }
  
  else {
     write("The ring tries to heal you and you suddenly feel better.\n");
     this_player()->reduce_hit_point(-40);
     this_player()->restore_spell_points(-40);
     
     return ( 1 );
   }
     
     return 1;
  }

read(str) {
  if (str=="inscription") {
     write("It was a long time ago that old Jack had hard fights against\n"+
        "evil demons and other creatures, therefore he created this strong\n"+
        "magic ring to transfer his spell points to some healing power,\n"+
        "to destruct this evil creatures and to light the darkness.\n\n"+
        "One tip the magic word is <rahanatem>.\n");
      return 1;
  }
}
     
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("ring");
     set_alias("jacks's ring");
     set_type("ring");
     set_short("Jack's ring");
     set_long("The ring of Jack's father, with a strange inscription on it.\n");
     set_arm_light(1); 
     set_ac(1);
     set_value(2000);
  }
}
   query_mage_wear() { return 1; }
   query_monk_wear() { return 1; }
