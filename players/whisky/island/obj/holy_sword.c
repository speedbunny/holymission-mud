/* Matt 7-29-93: WC lowered from 40 to 25, heal lowered by 60 points,
                 chance of heal lowered to 1 in 100. */
/* Uglymouth 930921 removed return 1 at end of reset(), and changed
      if(arg) return 1; to if(arg) return;  */

/* ######################################################################

                T H E  H O L Y  S W O R D (c) Whisky

   we define the weapon class 15+(10/2)=>course of the func agaist bad 
   monsters as: 22,5 =ok
   therefore its a holy weapon it  has a wc 35 against undead creatures !!!!
   ###################################################################### */
#define AL query_alignment()
inherit "/obj/weapon";


reset(arg) {
  ::reset();
  if (arg) return;
  
    set_name("sword");
    set_alias("holy sword");
    set_short("The Holy sword");
    set_long("A very strong sword, with a strange glance.\n");
    set_class(19);
   set_type(1);
    set_hit_func(this_object());
    set_value(20000);
    set_weight(2);
}

    weapon_hit(ob) {
   if ((random(100)<10) && (ob->AL < this_player()->AL)) {
    write("********************************************\n"+
          "    D I E  C R E A T U R E  D I E  !!!!\n"+ 
          "********************************************\n");
    say(this_player()->query_name()+" trusts the holy sword awfully against "+
        ob->query_name()+".\n");

     if (!random(100)) {
     write("You sword vibrates and you feel much better now.\n");
      this_player()->heal_player(20+random(this_player()->query_con()));
       }
    return 25; 
    }
   }
