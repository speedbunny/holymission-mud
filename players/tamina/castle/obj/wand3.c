inherit "/obj/weapon";
int i;       
reset(arg) {
 i=1;
 ::reset(arg);
if (arg) return;
    set_name("wand");
    set_id("wand");
    set_short("The Mega-Wand");
    set_long("This is a huge wand that is capable of demolishing anything.\n");
    set_value(10000);
    set_weight(3);
    set_type(3);
    set_hit_func(this_object());
 }
 
init(){
 ::init();
 add_action("kil","help");
}
 
kil(str){
 if (str=="me") { 
   i=2;
  return 1;
  }
 }

 weapon_hit(attacker){
  if (i==2){ 
   i=1;
   return 9000;
      }
   else
   return 20+random(10);
  }
