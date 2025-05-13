inherit "obj/weapon";

reset(arg)
{
if (arg) return;
    set_name("Staff of Sylvyn");
    set_id("Staff of Sylvyn");
    set_alt_name("staff");
    set_long(
    "This is the ancient and powerfull staff of the great Lord Sylvyn."+
    "A dragon's claw clutches a large crystal upon the top of the staff."+
    "It is said that only He may wield this for it knows it's own.\n");
    set_type(2);
    set_weight(5);
    set_value(200000);
    set_hit_func(this_object());
    if (this_player()->query_real_name!="waldo")
    {
      write("You cannot use this weapon.\n");
      destruct(this_object());
      }
 }

