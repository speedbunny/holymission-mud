
/* goblin chief */

#define CHAT ({"grnschkrrk","grrrrrrrr","shrlsnrzz","snrrrtatak"})

inherit "/obj/monster";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("goblin chief");
        set_alt_name("goblin");
        set_race("goblin");
        set_level(10);
        set_al(-500);
        add_money( 200 );
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
       

