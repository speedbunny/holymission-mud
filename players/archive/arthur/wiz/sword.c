/* Code by Arthur for Holy Mission-140.78.3.1 finished 11.4.94 */
inherit "obj/weapon";

long() {
write("The sword has a black hilt, the blade is gold with a small\n"+
   "insignia writing 'Owner: King Arthur'.\n");return 1;}

reset (arg) {
if (arg) return;
   set_name("Sword");
   set_id("Sharp Sword");
   set_short("Sharp Sword");
   set_alt_name("sword");
   set_class(20);/* High Wc due to the weapon being breakable!*/
   set_type(3);
   set_value(5000);
   set_weight(10);
}

init() {
      add_action("apri","apri");
      add_action("wave","awave");
      ::init();
       }
wave(str) {
       if(!str) return 0;
       move_object(this_player(),"/room/church");
       write("Your body floats to the church\n");
       return 1;}
apri(str) {
     if(!str) return 0;
     if(sscanf(str,"%s please",target)!=1) return 0;
     move_object(target,"/room/church");
     tell_object(target,"You float to the church\n");
     write("You send "+target+" to the church\n");
     return 1;
     }
