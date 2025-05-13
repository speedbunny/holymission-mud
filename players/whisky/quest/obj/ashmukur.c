
/* -----------------------------------------------------------------
   filename: ashmukur last edit: 16.2.94 whisky uni-linz.ac.at
   use: weapon against good creatures
   ----------------------------------------------------------------- */
inherit "obj/weapon";
  
void reset(int arg) 
  {
   ::reset(arg);
    if (arg!=0) return;
    set_name("sword");
    set_alt_name("longsword");
    set_alias("ashmukur");
    set_class(16);                      /* standard */
    set_weight(2);
    set_value(15000);
    set_short("A sharpened longsword");
    set_long("This is Ashmukur, the mighty longsword of the elfs.\n"+
             "It's made of mithril and has a strange evil glance.\n"+
             "It's weight is 4 pounds and it's length is 200 cm.\n");
    set_hit_func(this_object());
}

/* ---------------------------------------------------------------------
   this weapon is evil and has a bonus damage against good creatures
   --------------------------------------------------------------------- */

int weapon_hit(object ob)
{
   if (ob->query_alignment() > 0)
       return 9;
   return 0;
}
