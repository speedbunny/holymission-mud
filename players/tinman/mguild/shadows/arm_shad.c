
/* checking the allowance to wear an armour */

#define _ARM ({"ring","cloak","robe","amulet","boot","boots","other"})

inherit "/players/whisky/obj/std_shadow";

mixed wear(object ob)
{
     if (objectp(ob) && ob->armour_class() > 0 && !ob->query_monk_wear()
         && member_array(ob->query_type(),_ARM)==-1)
     {
         tell_object(me,
         "Your vows forbit you to wear this armour !\n");
         call_out("unwear",0,ob);
      }
   return me->wear(ob);
}

void unwear(object ob)
{
   tell_object(me,"You remove your worn armour.\n");
   command("remove "+ob->query_name(),me);
}
int arm_shad()
{
    return 1;
}
object arm_obj()
{
      return this_object();
}
