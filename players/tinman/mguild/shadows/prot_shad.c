
/* prot_shad */

inherit "/players/whisky/obj/std_shadow";

string friend;
object fobj;


mixed attack()
{
    object feind;

    feind = apply(call,me,"query_attack");

    if (friend && fobj && living(fobj) && environment(me)==environment(fobj)  
        && !objectp(apply(call,fobj,"query_attack")))
    {
         command("rescue "+apply(call,me,"query_real_name"),fobj);
         if (fobj && feind)
            funcall(call,fobj,"attack_object",feind);
    }
    return apply(call,me,"attack");
}

int prot_shad()
{
    return 1;
}

object prot_object()
{
    return this_object();
}

void set_protected(string fr)
{
     friend = fr;
}

string query_protected()
{
      return friend;
}

void set_protector(object o)
{
     fobj = o;
}

object query_protector()
{
      return fobj;
}
     

      
