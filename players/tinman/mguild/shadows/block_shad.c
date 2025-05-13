
/* block_shad */

inherit "/players/whisky/obj/std_shadow";
#define rnd random

string blocker, name;
object bl;
int wimpy;

mixed run_away()
{
    if (blocker && (bl = present(blocker,environment(me))) && ( rnd(2) ||
       (apply(call,me,"query_npc") && 
       (rnd(apply(call,me,"query_dex")) < (rnd(apply(call,bl,"query_dex"))*9))))) 
    {
         name = apply(call,me,"query_name");

         tell_object(me,
         "PANIC !!! "+capitalize(blocker)+
                    " is damn fast you can't stop the fight !\n");
         say(name+" PANICS, but "+capitalize(blocker)+
             " quickly blocks "+me->query_possessive()+" way !\n",bl,me);
         tell_object(bl,name+" PANICS, but you "+
                     "sucessfully block the exits !\n");  
         if (random(2))  /* change to loose an attack */
             funcall(call,me,"hold",bl,1);
         return 1;
     }
     apply(call,me,"run_away");
     destruct(this_object());
     return 1;
}

int random_move()
{
    return 1;
}
void set_blocker(string b)
{
     blocker = b;
}

string query_blocker()
{
      return blocker;
}

int block_shad()
{
    return 1;
}

object block_object()
{
    return this_object();
}

void end_shadow(object ob)
{
     apply(call,me,"set_trapped",0);
     ::end_shadow(ob);
}

void old_wimpy(int w)
{
     wimpy = w;
}     


