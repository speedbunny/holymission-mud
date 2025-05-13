#define _file "/players/sargon/magic/way_shad"
#include "/players/sargon/define.h"
inherit "obj/weapon";

reset(arg) {
  if (arg) return;

   set_name("Wayfinder");
   set_id("Wayfinder");
   set_short("Wayfinder, The Sword of Wisdom");
   set_alt_name("sword");
   set_alias("wayfinder");
   set_long("Even in dim light this weapon radiates a polished\n"+
            "look. The blade radiates power, not only from magic,\n"+
            "but the metal itself. There's a fine, faint mottled\n"+
            "pattern along the blade it seems to run deep into \n"+
            "the metal though the surface is flawlessly smooth.\n"+
            "On the black handle there's a simple symbol: \n"+
            "                   }--->  \n");
   set_value(6000);
   set_weight(6);
   set_type(1);
   set_hit_func(TO);
}

weapon_hit(ob) {
   say("Wayfinder begins to raddle and hum. The air starts to swirl\n"+
       "around Vulcan's Work. The world dims as Wayfinder slashes and\n"+
       "peirces "+ob->N+"'s body!\n");
 write("Wayfinder vibrates in your hand and surges with power as it cuts\n"+
       " "+ob->N+"'s body!\n");
 return 15+random(10);
}          

  init()
 {
   ::init();
   AA("find","find");
   AA("find","seek");
   AA("find","locate");
 }

 find (target)
 {

   object ob, ob2, ob3;
   int i;

   if (query_wielded() !=1)
   {
   write("You are not wielding Wayfinder!!\n");
   return 1;
   }

   if (!target)
{
   write("Wayfinder glows a blue hue, then dims.\n");
   return 1;
}

 ob = find_living(target);
   if (!ob)
{  
   write("Wayfinder glows a blue hue but then you realise that\n"+
         "it can not find "+(target)+".\n");
   return 1;
}

 ob2 = E(ob);
   if (!ob2)
{
   write("The Sword of Wisdom could not find "+(target)+".\n");
   return 1;
 }
 ob2->long();

 ob3 = all_inventory(ob2);
 write("\n    "+sizeof(ob3)+" objects in the same room.\n\n");
 for (i = 0; i <sizeof(ob3); i++)
  
  if (ob3[i]->short())
  write(ob3[i]->short() + ".\n");
  return 1;
}

int wield(string arg)
{
  object shad;

  if (id(arg) && !query_wielded())
  {
     if (TP->query_hands_free())
     {
        if (!this_player()->wis_shad())
        {
            shad = CO(_file);
            shad->SS(TP,0,"way_shad");
          }
     }
  }
return ::wield(arg);
}

 int un_wield()
 {
   if (TP->wis_shad())
      destruct(TP->wis_object());
   ::un_wield();
}	
    

   
