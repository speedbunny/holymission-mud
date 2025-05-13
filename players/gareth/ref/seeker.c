/* This is Mordred's Helmet of Seeking */

inherit "obj/armour";

#include "/obj/adjust.h"
#include "/players/tamina/defs.h"


void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("seeker");
    set_alias("helmet");
    set_type("helmet");
    set_short("Seeker, the Helmet");
    set_long(
  "This is the fabulous helmet crafted from purest gold for the great Knight,\n"+
  "Sir Mordred.  You can sense by the peculiar art in which the helmet was\n"+ 
  "made that there are magical properties associated with this item.\n");
    set_value(1500);
    set_ac(1);
    set_weight(4);

}
query_mage_wear()  { return 1; }
query_monk_wear()  { return 1; }
query_ninja_wear() { return 1; }

void init() 
{
  ::init();
  add_action("seek","seek");
}

seek (target)  
{
  object ob, ob2, ob3;
  int i;

  if (query_worn() != 1)
  {
    write("But you are not wearing Seeker!\n");
    return 1;
  }  

  if (!target)
  {
    write("The Helmet glows slightly, but fades again.\n"); 
    return 1; 
  }
  ob = find_living(target);
  if (!ob)
  {
    write("The Helmet glows bright for a second, but you realise\n"+ 
          "that your Helmet failed to seek out "+CAP(target)+".\n"); 
    return 1; 
  }
  ob2 = environment(ob);
  if (!ob2)
  { 
    write("The Helmet was unable to seek out "+CAP(target)+".\n"); 
    return 1; 
  }
  ob2->long();
  ob3 = all_inventory(ob2);
  write("\n    "+sizeof(ob3)+" objects in the same room.\n\n");
  for (i = 0; i < sizeof(ob3); i++)
    if (ob3[i]->short())
     write (ladjust (i + 1,5) + ob3[i]->short()+".\n");
  return 1;
}
