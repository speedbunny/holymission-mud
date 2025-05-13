/*
*  Arch_druid.c
*  Created by Texas 27 March 1998
*
*  This will become the main quest object for the 2nd level of the forest.
*
*  The following things will happen when killed by a player :
*
*  1 - The magical staff will disappear
*  2 - An invis item will appear on the player making all monsters who
*      live in the area aggressive towards them.
*  3 - Players will have xp set to minimum for their current level
*      Legends will lose 1,000,000xp x current Legend Level.
*
*
* WIZARDS :
*
*  KILLING THIS MONSTER CAUSES PLAYERS TO LOSE XP
*  
*  THIS IS INTENTINAL AND IS NOT A BUG OF ANY SORT

*/
inherit "/obj/monster";

object staff;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("arch druid");
  set_race("Treant");
  set_short("The forest Arch Druid");
  set_long(

"An old man in a long flowing robe that seems to have no colour of its\n"+
"own. Instead it catches the shades around it, so he appears to fade\n"+
"into the background. In his eyes is a hot potent look of extremity and triumph\n"+
"as if he has discovered within himself some unconquerable power.\n");

  set_level(100);
  set_gender(1);
  set_al(1000);

  staff = clone_object("/obj/weapon");
  staff->set_name("staff");
  staff->set_class(20);
  staff->set_hit_func(this_object());

  move_object(staff,this_object());
  command("wield staff",this_object());

  set_dead_ob(this_object());
}

attack()
{
  int i,sz;
  object *inroom;

  if(::attack() && (random(100 > 60)))
  {
    inroom=all_inventory(environment());
    sz=sizeof(inroom);
    for(i=0;i<sz;i++)
    {
      if(living(inroom[i]) && inroom[i]->query_race()!="Treant")
      {
        if(inroom[i] && inroom[i]->query_invis()) inroom[i]->set_vis();
        inroom[i]->catch_tell("The Trees lash out at you!\n");
        inroom[i]->hit_player(200/sz);
      }
    }
  return 1;
  }
 return;
}
int weapon_hit(object attacker) { return(random(100)); }

monster_died()
{
  if(this_player()->query_immortal()) return;
  destruct(staff);
  say(environment(),"The staff has magically disappeared!\n");
  return 0;
}
