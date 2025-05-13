/*
  Orc for the mob
  Coded by Silver : Sat 05-06-1995 2:26:52 pm
*/

#pragma strict_types
#pragma save_types

inherit "obj/monster.c";


void reset(int arg)
{
 ::reset(arg);
 if(!arg) {
 set_gender(1);
 set_aggressive(0);

 set_name("orc");
 set_alias("mob");
 set_alt_name("orc");
 set_short("Test orc from mob");
 set_long("This is an orc one form group which will capture players.\n"+
          "Not the head one.\n"
         );
 set_level(10);
 set_race("orc");

 set_whimpy(0);
 load_chat(10,({
 "The orc looks at you angrily.\n",
 "The orc pouts : Where is my leader ?\n"
              }));
 add_money(random(200));
}
}

// some specialities
 
 // new chk_attack function 
int chk_attack(object food)
  { 
   if ( !food ) return 0;  // none to attack
   
   if ( !interactive(food) ) return 1; // opponent is a monster
   
   return 0;  // it is not good subject to fight then
  }

 // start to be aggresive
 int _set_agg() {  set_aggressive(1); return 1; }
 
 int _alone_test() 
  { 
   object room;
   room = environment(this_object());
   if( !present("beer",room))  // it is alone
    {
     tell_room(room,
         "Orc says: I can't live without beer!\n");
      
     tell_room(room,
         "Orc dies.\n");
     destruct(this_object());
     return 1;
    }
  
   call_out("_alone_test",20);
   return 1;
  }

 void init()
 {
  ::init();
  add_action("_set_agg","agg");
  call_out("_alone_test",20);
 }

