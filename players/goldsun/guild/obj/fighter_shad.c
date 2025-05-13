
/* fighter shad 

   This is Shadow is build for the weapon specialisation of the 
   Fighter Guild. It raises the stat_damage of the Fighter,
   temporaly (for one hit) if the skillroll was sucessfully.
   This Shadow checks the 3 different types, slash, pierce and
   bludgeon.
   This Shadow also calculates the parry of the fighter !

                                 Whisky :*)
                                                                */ 

inherit "/players/whisky/obj/std_shadow";
int parry, berzerk;
string name;

   
// calculating the statdamage for weapon specialisation
int stat_dam(object weap)
{
    mixed skill;
    int type, dam;

    dam = apply(call,me,"stat_dam",weap);
 
    if (!weap) 
    {
        parry = 0;
        return dam;
    }
// hits-amounts who are depending on dex influence the parry  
    if (parry || !random(3))
        parry = 1;
    else 
        parry = 0;

     type = apply(call,weap,"query_weapon_type");
     name = apply(call,weap,"query_name");

     switch(type)
     {
        case 1:
          skill = funcall(call,me,"get_skill","fighter_bludgeon");
        break;
        case 2:
          skill = funcall(call,me,"get_skill","fighter_pierce");
        break;
        default:
          skill = funcall(call,me,"get_skill","fighter_slash");
        break;
     }
     if (!skill)
          return dam;

     skill = skill[0];

     return (random(101) > skill ? dam : (dam * 3 / 2));
}

// the parry
varargs int hit_player(int dam,int kind, mixed elem)
{
   mixed skill;
   string aname;

   if (!dam || !parry || kind || me==this_player() || !living(this_player()) ||
        apply(call,me,"query_holded") )
   {
       return apply(call,me,"hit_player",dam,kind,elem);
   }

   skill = funcall(call,me,"get_skill","fighter_parry");

   if (!skill)
        skill = 1;
   else 
      skill = skill[0];

   if (random(101) > skill) 
       return apply(call,me,"hit_player",dam,kind,elem);

// the parry is 0 after any parry try
   parry = 0;

   if (! (aname = apply(call,this_player(),"query_name")) )
          aname = "your victim";

// when the strength of the opponent is too high youll fail to parry
   if (apply(call,me,"query_str")/2 <
                   random( (apply(call,this_player(),"query_str")/2) ))
   {
       tell_object(me,
       "You try to PARRY, but "+aname+"s hit breaks through your defenses !\n");
       say(apply(call,me,"query_name")+" tried to PARRY, but "+aname+"s hit "+
       " broke through "+apply(call,me,"query_possessive")+" defenses !\n",me);
       return apply(call,me,"hit_player",dam,kind,elem);
   } 
   if (!name)
        name = "weapon";

    tell_object(me,
    "You make a quick move and PARRY "+aname+"s attack with your "+name+" !\n");
    say(apply(call,me,"query_name")+" PARRIES "+aname+"s attack with "+
        apply(call,me,"query_possessive")+" "+name+" !\n",me);
    return apply(call,me,"hit_player",0,kind,elem);
}

varargs mixed hold(object tp,int time)
{
   if (berzerk && random(3))
       return hold(tp,0);
   return hold(tp,time);
}

// during berzerk the player has a good saving throw against hold: ad&d
void set_berzerk(int x)
{
     berzerk = x;
}

int query_ac()
{
    if (berzerk)
        return (1+ apply(call,me,"query_ac")) / 2;
    return apply(call,me,"query_ac");
}

int fighter_shad() 
{ 
    return 1; 
}

// easier destructable
object fighter_object()
{
     return this_object();
}
