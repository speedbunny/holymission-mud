
/* goblin */

#define ART ({"small","dirty","large","grinning"})
#define CHAT ({"grnschkrrk","grrrrrrrr","shrlsnrzz","snrrrtatak"})

inherit "/players/whisky/mob";

void reset(int flag)
{
   int lv;

     ::reset(flag);
     if (flag == 0)
     {
        lv = random(4);
        set_name(ART[lv]+" goblin");
        set_alt_name("goblin");
        set_race("goblin");
        set_al(-100);
        lv = 2 + lv;
        set_level(lv);
        add_money( lv * 20);
        set_aggressive(1);
     }
}

mixed attack()
{
      if (::attack() && !random(8))
      {
         tell_room(environment(),query_name()+" says: "+CHAT[random(4)]+".\n");         return 1;
      }
   return 0;
}
       

void init()
{
   ::init();
     if (this_player()->query_race()=="centipede")
         attack_object(this_player());
}
