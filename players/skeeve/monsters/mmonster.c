inherit "/obj/monster";

#include "/players/skeeve/area.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("monster");
    set_alias("gmonster");
    set_alt_name("gmonster");
    set_short("A tiny monster");
    set_long("A tiny monster from the holy maze.\n");
    set_level(1);
    set_al(0);
    set_wc(1);
    set_ac(1); 
    set_chance(0);
    set_aggressive(0);
    set_whimpy(25);
    set_gender(1+random(2));
    set_size(1+random (4));
  }
}

init() {
  ::init();
/*  if (! (this_player()->query_immortal())
     && (this_player()->query_player())
     && ( this_player()->query_alignment() + random (101) > query_alignment()) 
     )
     attack_object(this_player());*/
}

/* must not leave the garden */
query_stay_maze() { return 1; }  
                     
config (version) {
  string *str;
  int i,*ints;

  str = ({"satan","devil","mummy","zombie","vampir", 
          "skeleton","spider","snake","bat","snail","fly"});
  i = (stringp(version))? member_array(version,str) : version;
  if (i<0)i=6+random(5);
 
  set_name(str[i]);
  
  set_short("A "+str[i]);
  set_long("A "+str[i]+"\n");
 
  ints = ({1,1,0,0,0,0,0,0,0,0,0});
  set_gender(ints[i]);

  ints = ({50,40,35,30,25,20,18,16,13,10,8});
  set_level(ints[i]);
  
  ints = ({27,25,22,20,17,15,14,13,11,10,6});
  set_wc(ints[i]);

  ints = ({15,13,11,10, 8, 6, 6, 5, 4, 3,1});
  set_ac(ints[i]); 

  ints = ({-9000,-7000,-5000,-3000,-2000,-1000,100,200,300,300,400});
  set_al(ints[version]);

  ints= ({90, 50}); /* all other 0 */
  if ((i<sizeof (ints)) && ints[i]) {
    set_chance(ints[i]);
    str = ({"The Satan casts a fireball at you.",
            "The satan casts a lightning at you.",
            "The devil shocks you.",
            "The devil cries."});
    set_spell_mess1(str[i]);
    set_spell_mess2(str[i+1]);
    ints = ({27,25});
    set_spell_dam(ints[i]);
  } else {
    set_sp(0);
    set_wc(query_wc()<<1);  /* *2 because no spells ! */
  }
  
  if (i==0)
    move_object(clone_object(WEAPONS+"holy_stuff"),this_object());
  else if (i==1)
    move_object(clone_object(ARMOURS+"holy_shield"),this_object());
  else if (i==2)
    move_object(clone_object(ARMOURS+"holy_robe"),this_object());
  else if (i==3)
    move_object(clone_object(ARMOURS+"holy_amulet"),this_object());

  set_alias("mmonster");
  
  return this_object();
}
