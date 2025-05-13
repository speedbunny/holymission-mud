#include "/players/sargon/define.h"
inherit "obj/weapon";

reset(arg) {
  if (arg) return;

   set_name("Dragonslicer");
   set_id("dragonslicer");
   set_short("Dragonslicer, The Sword of Heroes");
   set_alt_name("sword");
   set_alias("dragonslicer");
   set_long("Even in dim light this weapon radiates a polished\n"+
            "look. The sword gives off an aura of power, not only\n"+ 
            "from the magic, but from the metal itself. There is\n"+
            "a fine mottled pattern along the blade, it seems to\n"+
            "run deep into the metal though the surface is flawlessly\n"+
            "smooth. On the black handle there is a simple symbol:\n"+
            "A DRAGON \n");
   set_value(10000);
   set_weight(10);
   set_type(1);
   set_hit_func(TO);
}

weapon_hit(ob) {
 if ((ob->QR == "dragon") || (ob->QR == "drake") || (ob->QR == "draconian"))
    {

 write("Dragonslicer, roars a shrill sound as its power builds up\n"+ 
       "and weaves through "+ob->N+"'s scales!\n");
 say("Dragonslicer glows white as it's embedded deep into\n"+             
     ""+ob->N+"'s body!\n");
 return 100+random(100);
}          
}
