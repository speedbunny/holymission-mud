

/* --------------------------------------------------------------------
    filename: thunderblade.c last edit: whisky uni-linz.ac.at 
   -------------------------------------------------------------------- */

inherit "/obj/weapon";

  reset(arg)
  {
   ::reset(arg);
   set_name("thunderblade");
   set_alt_name("blade");
   set_hit_func(this_object());
   set_short("Thunderblade");
   set_long(
   "You see a long mithril sword with a sharp blade and a handy\n"+
   "shaft covered with soft leather. It glows in a soft blue aura.\n"+
   "This sword somehow looks like an evil lifesucker.\n");
   set_weight(4);
   set_class(16);
   set_value(8000);
  }

magic_hit(ob)
 {
  if (random(10) <= 1)
  {
     write("Your thunderblade sucks the life out of "+ob->query_name()+
            "'s body.\n");
     write(this_player()->query_name()+"'s thunderblade sucks the life out of "+           ob->query_name()+"'s body.\n");
     if (ob->query_alignment() < -100)
         return (4+random(12));   /*  5 / 5 = 1 wc = 17  against evil */
     else 
         return (80+random(40));    /* 40 / 5 = 8 wc = 23  against good */
   }
  return 0;
}

   



   



