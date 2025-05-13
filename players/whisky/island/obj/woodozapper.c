#define TP this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()
#define TPL TP->query_level()
inherit "obj/weapon";

  reset(arg) {
   ::reset(arg);
 if (arg) return;

  set_name("zapper");
  set_class(12);
  set_weight(1);
  set_light(1);
  set_value(2000);
  set_hit_func(this_object());
  set_alias("voodozapper");
  set_short("A Voodozapper");
  set_long("The mighty weapon of the dangerous zuluman.\n"+
           "It glowes in a strange red light.\n");
}
 weapon_hit(ob) {  
  int i;
  i = random(40);
  if (!i)
 {
    write(" Z Z Z A A P P p p !!!!!!!!!!!!!!!!!!!!!!!!\n\n\n"+
        "You flash out a bright beam out from your zapper.\n\n\n"+
        ob->query_name()+" is almost deadly hurt.\n\n\n");
    say(" Z Z Z A A P P p p !!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n"+
        TPN+" flashes out a bright beam from "+TPP+" zapper.\n\n\n"+
        ob->query_name()+" is almost deadly hurt.\n\n\n");
    return 180;
   /* 10 + 6 == wc 16 :) */

   }
   return;
 }

